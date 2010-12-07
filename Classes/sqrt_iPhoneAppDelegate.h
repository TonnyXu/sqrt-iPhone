//
//  sqrt_iPhoneAppDelegate.h
//  sqrt-iPhone
//
//  Created by Tonny on 10/12/07.
//  Copyright 2010 genesix Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class sqrt_iPhoneViewController;

@interface sqrt_iPhoneAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    sqrt_iPhoneViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet sqrt_iPhoneViewController *viewController;

@end

