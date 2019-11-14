/** 
 * Driver class for horner's method optimization
 *
 * Author: Zach Tucker
 * Version: 11122019
 */

#include <stdio.h>
#include <stdlib.h>
#include "horners.h"

int main(int argc, char **argv) {
    
    long degree = strtol(argv[1], NULL, 10);
    long i;
    double x = 2.15;
    double a[200000]; // 200,000 elements
    double p;

    for (i = 0; i + 5 < 200000; i++) {
        a[i] = 1.1;
        a[i + 1] = 2.2;
        a[i + 2] = 3.3;
        a[i + 3] = 4.4;
        a[i + 4] = 5.5;
    }
    
    // p = poly(a, x, degree);
    // p = unroll2_poly(a, x, degree);
    // p = unroll2x2_poly(a, x, degree);
    // p = unroll4_poly(a, x, degree);
    // p = unroll4x4_poly(a, x, degree);
    // p = polyh(a, x, degree);
    // p = unroll2_polyh(a, x, degree);
    // p = unroll4_polyh(a, x, degree);
}

