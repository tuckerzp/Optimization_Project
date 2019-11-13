#include "minunit/minunit.h"
#include "horners.h"
#include "stdlib.h"

MU_TEST(test_horners) {
    double test = 0.0;
    double compare = 0.0;
    double tolerance = 0.1;
    
    long degree = 500000;
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
    
    compare = poly(a, x, degree);
    test = poly(a, x, degree);    // Change this to test

    mu_check(abs(test - compare) < tolerance);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_horners);
}
   
int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return minunit_status;
}

