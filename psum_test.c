#include "minunit/minunit.h"
#include "psum.h"
#include "stdlib.h"

MU_TEST(test_psum) {
    double tolerance = 0.1;
    
    long n = 200000;
    long i;
    float a[n];
    float test[n];
    float compare[n];

    for (i = 0; i + 5 < n; i++) {
        a[i] = 1.1;
        a[i + 1] = 2.2;
        a[i + 2] = 3.3;
        a[i + 3] = 4.4;
        a[i + 4] = 5.5;
    }
    
    psum1(a, compare, n);
    psum1a(a, test, n);    // Change this to test
    
    for (i = 0; i < n; i++) {
        mu_check(abs(test[i] - compare[i]) < tolerance);
    }
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_psum);
}
   
int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return minunit_status;
}

