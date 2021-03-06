//
//  chat_client.cpp
//  iOSSocketTest
//
//  Created by 江磊 on 2018/10/06.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "chat_client.hpp"

void chat_client::start_connect(){
    do_connect(endpoints_);
}
void write(const chat_message& msg);

void chat_client::close() {
    boost::asio::post(io_context_, [this]() { socket_.close(); });
}
void chat_client::write(const chat_message& msg) {
    boost::asio::post(io_context_,
                      [this, msg]() {
                          bool write_in_progress = !write_msgs_.empty();
                          write_msgs_.push_back(msg);
                          if (!write_in_progress) {
                              do_write();
                          }
                      });
}

void chat_client::do_connect(const tcp::resolver::results_type& endpoints) {
    boost::asio::async_connect(socket_, endpoints,
                               [this](boost::system::error_code ec, tcp::endpoint) {
                                   if (!ec) {
                                       do_read_header();
                                   }
                               });
}

void chat_client::do_read_header() {
    boost::asio::async_read(socket_,
                            boost::asio::buffer(read_msg_.data(), chat_message::header_length),
                            [this](boost::system::error_code ec, std::size_t /*length*/) {
                                if (!ec && read_msg_.decode_header()) {
                                    do_read_body();
                                } else {
                                    socket_.close();
                                }
                            });
}

void chat_client::do_read_body(){
    boost::asio::async_read(socket_,
                            boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                            [this](boost::system::error_code ec, std::size_t /*length*/) {
                                if (!ec) {
                                    SendMessageResponse msg;
                                    msg.ParseFromArray(read_msg_.body(), static_cast<int>(read_msg_.body_length()));
                                    recieveMessage(msg);
                                    do_read_header();
                                } else{
                                    socket_.close();
                                }
                            });
}

void chat_client::do_write() {
    boost::asio::async_write(socket_,
                             boost::asio::buffer(write_msgs_.front().data(),
                                                 write_msgs_.front().length()),
                             [this](boost::system::error_code ec, std::size_t /*length*/) {
                                 if (!ec) {
                                     write_msgs_.pop_front();
                                     if (!write_msgs_.empty()) {
                                         do_write();
                                     }
                                 } else {
                                     socket_.close();
                                 }
                             });
}
