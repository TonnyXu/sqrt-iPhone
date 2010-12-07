//
//  sqrt_iPhoneViewController.m
//  sqrt-iPhone
//
//  Created by Tonny on 10/12/07.
//  Copyright 2010 genesix Inc. All rights reserved.
//

#import "sqrt_iPhoneViewController.h"

#include <stdio.h>
#include <sys/time.h>
#include <math.h>


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


void do_system_sqrt(){
    struct timeval start, end, result;
    double total;
    gettimeofday(&start, NULL);
    float b;
    for (int i = 0; i < 1000000; i++) {
        b = 1/sqrt((float)i);
    }
    gettimeofday(&end, NULL);
    
    timeval_subtract(&result, &end, &start);
    total = result.tv_sec * 1000000 + result.tv_usec;
    printf("================ system sqrt() ================\n");
    printf("Caculate 1,000,000,000 sqrt cost %12.1f nanoseconds.\n\n", total);
    
}

float SquareRootFloat(float number) {
    long i;
    float x, y;
    const float f = 1.5F;
    
    x = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * ( float * ) &i;
    y  = y * ( f - ( x * y * y ) );
    //    y  = y * ( f - ( x * y * y ) );
    return number * y;
}

float Q_inverseSqrt(float number) {
    long i;
    float x, y;
    const float f = 1.5F;
    
    x = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * ( float * ) &i;
    y  = y * ( f - ( x * y * y ) );
    //    y  = y * ( f - ( x * y * y ) );
    return  y;
}

void do_carmack_sqrt(){
    struct timeval start, end, result;
    double total;
    gettimeofday(&start, NULL);
    for (int i = 0; i < 1000000; i++) {
        Q_inverseSqrt((float)i);
    }
    gettimeofday(&end, NULL);
    
    timeval_subtract(&result, &end, &start);
    total = result.tv_sec * 1000000 + result.tv_usec;
    printf("================ carmack sqrt() ================\n");
    printf("Caculate 1,000,000,000 sqrt cost %12.1f nanoseconds.\n\n", total);
    
}


@implementation sqrt_iPhoneViewController



/*
// The designated initializer. Override to perform setup that is required before the view is loaded.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}
*/

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView {
}
*/


- (void)viewDidLoad {
    [super viewDidLoad];
    do_system_sqrt();
    do_carmack_sqrt();
}



/*
// Override to allow orientations other than the default portrait orientation.
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}
*/

- (void)didReceiveMemoryWarning {
	// Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
	
	// Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
	// Release any retained subviews of the main view.
	// e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}

@end
