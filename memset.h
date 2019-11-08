#include <stdint.h>

void *basic_memset(void *s, int c, size_t n);
void *first_memset(void *s, int c, size_t n);
void *unroll16_memset(void *s, int c, size_t n);
void *unroll8_memset(void *s, int c, size_t n);
void *unroll4_memset(void *s, int c, size_t n);
void *unroll2_memset(void *s, int c, size_t n);

