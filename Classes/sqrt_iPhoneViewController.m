//
//  sqrt_iPhoneViewController.m
//  sqrt-iPhone
//
//  Created by Tonny on 10/12/07.
//  Copyright 2010 genesix Inc. All rights reserved.
//

#import "sqrt_iPhoneViewController.h"
#include "sqrt.h"

@implementation sqrt_iPhoneViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    printf("========================== iOS ==========================\n");
    do_system_sqrt (65535.f, 100000000);
    do_carmack_sqrt(65535.f, 100000000);
    do_system_inverse_sqrt (65535.f, 100000000);
    do_carmack_inverse_sqrt(65535.f, 100000000);
}

@end
