//
//  ViewController.m
//  iOSSocketTest
//
//  Created by 江磊 on 2018/10/05.
//  Copyright © 2018 江磊. All rights reserved.
//

#import "ViewController.h"
#include <boost/asio.hpp>
#include <iostream>
#include <boost/array.hpp>
#include "chat_service.hpp"

@interface ViewController (){
    chat_service *chatService;
}

@end

@implementation ViewController

using boost::asio::ip::tcp ;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    chatService = new chat_service();

}

- (IBAction)actionGetTime:(id)sender {
    try {
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query("192.168.199.202","8000");
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        
        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);
        for(;;){
            boost::array<char, 128> buff;
            boost::system::error_code error;
            size_t len = socket.read_some(boost::asio::buffer(buff),error);
            if (error == boost::asio::error::eof) {
                break;
            }else if (error)
                throw boost::system::system_error(error);
            std::cout.write(buff.data(), len);
            
            NSString *str = [[NSString alloc]initWithBytes:buff.data() length:len encoding:NSUTF8StringEncoding];
            NSString *string = [self.textViewMsg.text stringByAppendingString:str?str:@""];
            [self.textViewMsg setText:string];
            NSRange bottom = NSMakeRange(self.textViewMsg.text.length -1, 1);
            [self.textViewMsg scrollRangeToVisible:bottom];
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

- (IBAction)actionEcho:(id)sender {
    try {
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::socket socket(io_service);
        boost::asio::connect(socket,  resolver.resolve({"192.168.199.202","8001"}));
        
        std::string msg = "this is wjl";
        size_t length = msg.length();
        
        boost::asio::write(socket, boost::asio::buffer(msg,length));
        
        char reply[1024];
        size_t replyLength = boost::asio::read(socket, boost::asio::buffer(reply,length));
        std::cout << "reply is -> ";
        std::cout.write(reply, replyLength);
        std::cout << "\n";
        NSString *str = [[NSString alloc]initWithBytes:reply length:replyLength encoding:NSUTF8StringEncoding];
        NSString *string = [self.textViewMsg.text stringByAppendingString:str?str:@""];
        [self.textViewMsg setText:string];
        NSRange bottom = NSMakeRange(self.textViewMsg.text.length -1, 1);
        [self.textViewMsg scrollRangeToVisible:bottom];
    } catch (std::exception &excep) {
        std::cout <<excep.what()<<std::endl;
    }
}

- (IBAction)actionChat:(id)sender {
    chatService -> start_chat_service();
}

- (IBAction)actionStopChat:(id)sender {
    chatService -> stop_chat_service();
}

@end
