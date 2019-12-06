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
        *(byte + i) = (unsigned char) c;
    }

    // Write 8 bytes at a time

    uint64_t *word_ptr = (uint64_t*) schar;

    while (cnt + 8 < n) {
        *word_ptr++ = word;
        cnt += 8;
    }

    // Finish up!

    schar = (unsigned char*) word_ptr;

    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    return s;
}

void *unroll16_memset(void *s, int c, size_t n)
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
        *(byte + i) = (unsigned char) c;
    }

    // Write 8 bytes at a time

    uint64_t *word_ptr = (uint64_t*) schar;

    while (cnt + 128 < n) {
        *word_ptr = word;
        *(word_ptr + 1) = word;
        *(word_ptr + 2) = word;
        *(word_ptr + 3) = word;
        *(word_ptr + 4) = word;
        *(word_ptr + 5) = word;
        *(word_ptr + 6) = word;
        *(word_ptr + 7) = word;
        *(word_ptr + 8) = word;
        *(word_ptr + 9) = word;
        *(word_ptr + 10) = word;
        *(word_ptr + 11) = word;
        *(word_ptr + 12) = word;
        *(word_ptr + 13) = word;
        *(word_ptr + 14) = word;
        *(word_ptr + 15) = word;
        word_ptr += 16;
        cnt += 128;
    }

    while (cnt + 8 < n) {
        *word_ptr++ = word;
        cnt += 8;
    }

    // Finish up!

    schar = (unsigned char*) word_ptr;

    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    return s;
}

void *unroll8_memset(void *s, int c, size_t n)
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
        *(byte + i) = (unsigned char) c;
    }

    // Write 8 bytes at a time

    uint64_t *word_ptr = (uint64_t*) schar;

    while (cnt + 64 < n) {
        *word_ptr = word;
        *(word_ptr + 1) = word;
        *(word_ptr + 2) = word;
        *(word_ptr + 3) = word;
        *(word_ptr + 4) = word;
        *(word_ptr + 5) = word;
        *(word_ptr + 6) = word;
        *(word_ptr + 7) = word;
        word_ptr += 8;
        cnt += 64;
    }

    while (cnt + 8 < n) {
        *word_ptr++ = word;
        cnt += 8;
    }

    // Finish up!

    schar = (unsigned char*) word_ptr;

    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    return s;
}

void *unroll4_memset(void *s, int c, size_t n)
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
        *(byte + i) = (unsigned char) c;
    }

    // Write 8 bytes at a time

    uint64_t *word_ptr = (uint64_t*) schar;

    while (cnt + 32 < n) {
        *word_ptr = word;
        *(word_ptr + 1) = word;
        *(word_ptr + 2) = word;
        *(word_ptr + 3) = word;
        word_ptr += 4;
        cnt += 32;
    }

    while (cnt + 8 < n) {
        *word_ptr++ = word;
        cnt += 8;
    }

    // Finish up!

    schar = (unsigned char*) word_ptr;

    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    return s;
}

void *unroll2_memset(void *s, int c, size_t n)
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
        *(byte + i) = (unsigned char) c;
    }

    // Write 8 bytes at a time

    uint64_t *word_ptr = (uint64_t*) schar;

    while (cnt + 16 < n) {
        *word_ptr = word;
        *(word_ptr + 1) = word;
        word_ptr += 2;
        cnt += 16;
    }

    while (cnt + 8 < n) {
        *word_ptr++ = word;
        cnt += 8;
    }

    // Finish up!

    schar = (unsigned char*) word_ptr;

    while (cnt < n) {
        *schar++ = (unsigned char) c;
        cnt++;
    }

    return s;
}

