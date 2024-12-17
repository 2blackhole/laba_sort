#pragma once
#include <stdbool.h>
#include <stdlib.h>
#define R_MAX 500


typedef enum {
    RANDOM = 0,
    SORTED = 1,
    INVERTED = 2
} array_key;

double* generate_array(array_key, int n);

int* generate_array_int(array_key array_key, size_t n);

void test_n(void (*sort) (double* a, int n), int n, array_key array_key, bool print_arrays);

void test_se(void (*sort) (double* a, int s, int e), int n, array_key array_key, bool print_arrays);

void test_int(void (*sort) (int* a, size_t n), size_t n, array_key array_key, bool print_arrays);

