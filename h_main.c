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
    double a[degree];
    double p;

    for (i = 0; i + 5 < degree; i++) {
        a[i] = 1.1;
        a[i + 1] = 2.2;
        a[i + 2] = 3.3;
        a[i + 3] = 4.4;
        a[i + 4] = 5.5;
    }
    for (; i < degree; i++) {
        a[i] = 6.6;
    }

    // p = poly(a, x, degree);
    // p = polyh(a, x, degree;
}
