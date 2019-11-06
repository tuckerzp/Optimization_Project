#include "minunit/minunit.h"
#include "memset.h"

MU_TEST(test_memset_unalign) {
    uint8_t x[57];
    uint8_t *r;

    memset(&x, '!', 57);

    for (int i = 0; i < 57; i++) {
        mu_check(*(x+i) == '!');
    }
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_memset_unalign);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return minunit_status;
}
