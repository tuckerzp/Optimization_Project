#include "minunit/minunit.h"
#include "horners.h"
#include "stdlib.h"

MU_TEST(test_horners) {
    double test = 0.0;
    double compare = 0.0;
    
    long degree = 100000;
    long i;
    double x = 0.914;
    double a[degree + 1];
    double p;

    for (i = 0; i + 5 <= degree; i += 5) {
        a[i] = 0.561;
        a[i + 1] = 0;
        a[i + 2] = 0.06;
        a[i + 3] = 2.14892;
        a[i + 4] = 10;
    }
    for (; i <= degree; i++) {
        a[i] = 1;
    }
    
    compare = poly(a, x, degree);

    mu_assert_double_eq(compare, unroll2_poly(a, x, degree));
    mu_assert_double_eq(compare, unroll2x2_poly(a, x, degree));
    mu_assert_double_eq(compare, unroll4_poly(a, x, degree));
    mu_assert_double_eq(compare, unroll4x4_poly(a, x, degree));
    mu_assert_double_eq(compare, unroll2a_poly(a, x, degree));
    mu_assert_double_eq(compare, unroll4a_poly(a, x, degree));
    mu_assert_double_eq(compare, unroll2a_poly_mix(a, x, degree));
    mu_assert_double_eq(compare, unroll4a_poly_mix(a, x, degree));
    mu_assert_double_eq(compare, unroll2_polyh(a, x, degree));
    mu_assert_double_eq(compare, unroll4_polyh(a, x, degree));
    mu_assert_double_eq(compare, unroll2a_polyh(a, x, degree));
    mu_assert_double_eq(compare, unroll4a_polyh(a, x, degree));

}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_horners);
}
   
int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return minunit_status;
}

