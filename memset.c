#include <stddef.h>
#include "memset.h"

/* Basic implementation of memset */
void *basic_memset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    unsigned char *schar = s;
    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }
    return s;
}

void *first_memset(void *s, int c, size_t n)
{
    size_t cnt = 0;
    unsigned char *schar = s;

    // Write bytes before soonest 8 byte alignment

    while (cnt < n && ((uint64_t) s + cnt) % 8 != 0) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    // Set up 8 byte number

    uint64_t word;
    uint8_t *byte = (uint8_t*) &word;

    for (int i = 0; i < 8; i++) {
        *(byte + i) = c;
    }

    // Write 8 bytes at a time

    uint64_t *rename = (uint64_t*) schar;

    while (cnt + 8 < n) {
        *rename++ = word;
        cnt += 8;
    }

    // Finish up!

    schar = (unsigned char*) rename;

    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    return s;
}

