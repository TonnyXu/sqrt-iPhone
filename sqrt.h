/*
 *  sqrt.h
 *  sqrt-iPhone
 *
 *  Created by Tonny on 10/12/09.
 *  Copyright 2010 genesix Inc. All rights reserved.
 *
 */

#include <stdio.h>
#include <sys/time.h>
#include <math.h>

#ifndef __SQRT_H__
#define __SQRT_H__

int
timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y);

float Q_sqrt(float number);
float Q_InvSqrt(float number);
void do_carmack_inverse_sqrt(float number, int times);
void do_system_inverse_sqrt(float number, int times);
void do_carmack_sqrt(float number, int times);
void do_system_sqrt(float number, int times);

#endif //__SQRT_H__

