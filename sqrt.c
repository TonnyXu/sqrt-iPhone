/*
 *  sqrt.c
 *  sqrt-iPhone
 *
 *  Created by Tonny on 10/12/09.
 *  Copyright 2010 genesix Inc. All rights reserved.
 *
 */

#include "sqrt.h"



/* 
 From GNU page: http://www.gnu.org/s/libc/manual/html_node/Elapsed-Time.html
 
 Subtract the `struct timeval' values X and Y,
 storing the result in RESULT.
 Return 1 if the difference is negative, otherwise 0.  
 */

int
timeval_subtract (result, x, y)
struct timeval *result, *x, *y;
{
    /* Perform the carry for the later subtraction by updating y. */
    if (x->tv_usec < y->tv_usec) {
        int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
        y->tv_usec -= 1000000 * nsec;
        y->tv_sec += nsec;
    }
    if (x->tv_usec - y->tv_usec > 1000000) {
        int nsec = (x->tv_usec - y->tv_usec) / 1000000;
        y->tv_usec += 1000000 * nsec;
        y->tv_sec -= nsec;
    }
    
    /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
    result->tv_sec = x->tv_sec - y->tv_sec;
    result->tv_usec = x->tv_usec - y->tv_usec;
    
    /* Return 1 if result is negative. */
    return x->tv_sec < y->tv_sec;
}

float Q_sqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    
    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;  // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 ); // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
                                              // y  = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed
    return number * y;
}

float Q_InvSqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    
    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;  // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 ); // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
                                              // y  = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed
    
    return y;
}


void do_carmack_inverse_sqrt(float number, int times){
    struct timeval start, end, result;
    double total;
    gettimeofday(&start, NULL);
    float b;
    for (int i = 0; i < times; i++) {
        b= Q_InvSqrt(number);
    }
    gettimeofday(&end, NULL);
    
    timeval_subtract(&result, &end, &start);
    total = result.tv_sec * 1000000 + result.tv_usec;
    printf("* carmack inverse sqrt() \n\t");
    printf("1/sqrt(%12.1f) = %5.12f | using %12.1f nanoseconds\n", number, b, total);
    
}


void do_system_inverse_sqrt(float number, int times){
    struct timeval start, end, result;
    double total;
    gettimeofday(&start, NULL);
    float b;
    for (int i = 0; i < times; i++) {
        b = 1.0/sqrt(number);
    }
    gettimeofday(&end, NULL);
    
    timeval_subtract(&result, &end, &start);
    total = result.tv_sec * 1000000 + result.tv_usec;
    printf("* system inverse sqrt() \n\t");
    printf("1/sqrt(%12.1f) = %5.12f | using %12.1f nanoseconds\n", number, b, total);
    
}

void do_carmack_sqrt(float number, int times){
    struct timeval start, end, result;
    double total;
    gettimeofday(&start, NULL);
    float b;
    for (int i = 0; i < times; i++) {
        b= Q_sqrt(number);
    }
    gettimeofday(&end, NULL);
    
    timeval_subtract(&result, &end, &start);
    total = result.tv_sec * 1000000 + result.tv_usec;
    printf("* carmack sqrt() \n\t");
    printf("sqrt(%12.1f) = %5.12f | using %12.1f nanoseconds\n", number, b, total);
    
}


void do_system_sqrt(float number, int times){
    struct timeval start, end, result;
    double total;
    gettimeofday(&start, NULL);
    float b;
    for (int i = 0; i < times; i++) {
        b = sqrt(number);
    }
    gettimeofday(&end, NULL);
    
    timeval_subtract(&result, &end, &start);
    total = result.tv_sec * 1000000 + result.tv_usec;
    printf("* system sqrt() \n\t");
    printf("sqrt(%12.1f) = %5.12f | using %12.1f nanoseconds\n", number, b, total);
    
}

