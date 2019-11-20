#include "minunit/minunit.h"
#include "psum.h"
#include "stdlib.h"

MU_TEST(test_psum) {
    double tolerance = 0.1;
    
    long n = 2000;
    long i;
    float a[n];
    float p2[n];
    float p4[n];
    float p2a[n];
    float p3a[n];
    float compare[n];

    for (i = 0; i < n - 4; i += 5) {
        a[i] = 0.5;
        a[i + 1] = 0.25;
        a[i + 2] = 0.125;
        a[i + 3] = 1;
        a[i + 4] = 0.0625;
    }
    
    psum1(a, compare, n);
    psum2(a, p2, n);
    psum4(a, p4, n);
    psum2a(a, p2a, n);
    psum3a(a, p3a, n);
    
    for (i = 0; i < n; i++) {
        mu_assert_double_eq(compare[i], p2[i]);
        mu_assert_double_eq(compare[i], p4[i]);
        mu_assert_double_eq(compare[i], p2a[i]);
        mu_assert_double_eq(compare[i], p3a[i]);
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

