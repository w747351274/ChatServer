//
//  ViewController.h
//  iOSSocketTest
//
//  Created by 江磊 on 2018/10/05.
//  Copyright © 2018 江磊. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (weak, nonatomic) IBOutlet UITextView *textViewMsg;

- (IBAction)actionGetTime:(id)sender;
- (IBAction)actionEcho:(id)sender;
- (IBAction)actionChat:(id)sender;
- (IBAction)actionStopChat:(id)sender;


@end

