/**
 * Driver method for psum
 *
 * Author: Zach Tucker
 * Version: 11142019
 */

#include <stdio.h>
#include <stdlib.h>
#include "psum.h"
    
int main(int argc, char **argv) {
    
    long n = strtol(argv[1], NULL, 10);
    long i;
    float a[200000]; // 200,000 elements
    float p[200000];

    for (i = 0; i + 5 < 200000; i++) {
        a[i]     = 1.1;
        a[i + 1] = 2.2;
        a[i + 2] = 3.3;
        a[i + 3] = 4.4;
        a[i + 4] = 5.5;
    }

    // psum1(a, p, n);
    // psum2(a, p, n);
    // psum1a(a, p, n);
}
