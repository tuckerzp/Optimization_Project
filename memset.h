#include <stdint.h>

void *basic_memset(void *s, int c, size_t n);
void *first_memset(void *s, int c, size_t n);
void *unroll_memset(void *s, int c, size_t n);
