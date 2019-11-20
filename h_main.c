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
    double x = 0.0625;
    double a[200001]; // 200,001 elements
    double p;

    for (i = 0; i + 5 < 200000; i += 5) {
        a[i] = 0.292;
        a[i + 1] = 6;
        a[i + 2] = 1;
        a[i + 3] = 0;
        a[i + 4] = 0.8;
    }
    
    // p = poly(a, x, degree);
    // p = unroll2_poly(a, x, degree);
    // p = unroll2x2_poly(a, x, degree);
    // p = unroll4_poly(a, x, degree);
    // p = unroll4x4_poly(a, x, degree);
    // p = unroll2a_poly(a, x, degree);
    // p = unroll4a_poly(a, x, degree);
    // p = unroll2a_poly_mix(a, x, degree);
    // p = unroll4a_poly_mix(a, x, degree);
    // p = polyh(a, x, degree);
    // p = unroll2_polyh(a, x, degree);
    // p = unroll4_polyh(a, x, degree);
    // p = unroll2a_polyh(a, x, degree);
    // p = unroll4a_polyh(a, x, degree);
}

