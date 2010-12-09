/*
 *  main.c
 *  sqrt-iPhone
 *
 *  Created by Tonny on 10/12/09.
 *  Copyright 2010 genesix Inc. All rights reserved.
 *
 */
#include "sqrt.h"

int main (int argc, const char * argv[]) {
    
    printf("========================== Mac OSX ==========================\n");
    do_system_sqrt (65535.f, 1000000000);
    do_carmack_sqrt(65535.f, 1000000000);
    do_system_inverse_sqrt (65535.f, 1000000000);
    do_carmack_inverse_sqrt(65535.f, 1000000000);
    return 0;
}
