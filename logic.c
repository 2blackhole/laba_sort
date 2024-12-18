#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>
#include <math.h>
#include "logic.h"

double* generate_array(array_key array_key, int n) {
    double* array = (double*)malloc(sizeof(double) * n);
    srand(time(0));
    if (array_key == RANDOM) {
        for (int i = 0; i < n; i++) {
            array[i] = fmod((double)rand() / (RAND_MAX + 3.0) + (double)rand(), R_MAX);
        }
        return array;
    }
    else if(array_key == SORTED) {
        array[0] = fmod((double)rand() / (RAND_MAX + 3.0) + (double)rand(), R_MAX);
        for (int i = 1; i < n; i++) {
            array[i] = array[i - 1] + fmod((double)rand() / (RAND_MAX + 3.0) + (double)rand(), R_MAX);
        }
        return array;
    }
    double * a = generate_array(SORTED, n);
    for (int i = 0; i < n; i++) {
        array[i] = a[n - i - 1];
    }
    free(a);
    return array;
}

int* generate_array_int(array_key array_key, size_t n) {
    int* array = (int*)malloc(sizeof(int) * n);
    srand(time(0));
    if (array_key == RANDOM) {
        for (int i = 0; i < n; i++) {
            array[i] = ((int)rand()) % (int)R_MAX;
        }
        return array;
    }
    else if(array_key == SORTED) {
        array[0] = ((int)rand()) % (int)(R_MAX / 5);
        for (int i = 1; i < n; i++) {
            array[i] = array[i - 1] + 1;
        }
        return array;
    }
    int * a = generate_array_int(SORTED, n);
    for (int i = 0; i < n; i++) {
        array[i] = a[n - i - 1];
    }
    free(a);
    return array;
}


void test_n(void (*sort) (double* a, int n), int n, array_key array_key, bool print_arrays) {

    int true_sort = 1;
    double * array = generate_array(array_key, n);


    if (print_arrays) {
        printf("************** Generated array **************\n");
        for (int i = 0; i < n; i++) {
            printf("%f ", array[i]);
        }
        printf("\n");
    }

    time_t start = clock();

    sort(array, n);

    time_t end = clock();
    double dt =  (double) (end - start) / (CLOCKS_PER_SEC );

    for (int i = 1; i < n; i++) {
        if (array[i] < array[i - 1]) {
            true_sort = 0;
        }
    }

    if (print_arrays) {
        printf("************** Sorted array **************\n");
        for (int i = 0; i < n; i++) {
            printf("%f ", array[i]);
        }
        printf("\n");
    }
    if (!true_sort) {
        printf("Invalid array");
        free(array);
        return;
    }

    printf("Sorting time : %f seconds. Amount of elements : %d, Type of array :  %d", dt, n, array_key);

    free(array);
}

void test_se(void (*sort) (double* a, int s, int e), int n, array_key array_key, bool print_arrays) {

    double * array = generate_array(array_key, n);
    int true_sort = 1;

    if (print_arrays) {
        printf("************** Generated array **************\n");
        for (int i = 0; i < n; i++) {
            printf("%f ", array[i]);
        }
        printf("\n");
    }

    time_t start = clock();

    sort(array, 0, n - 1);

    time_t end = clock();
    double dt =  (double) (end - start) / (CLOCKS_PER_SEC );

    for (int i = 1; i < n; i++) {
        if (array[i] < array[i - 1]) {
            true_sort = 0;
        }
    }

    if (print_arrays) {
        printf("************** Sorted array **************\n");
        for (int i = 0; i < n; i++) {
            printf("%f ", array[i]);
        }
        printf("\n");
    }
    if (!true_sort) {
        printf("Invalid array");
        free(array);
        return;
    }
    printf("Sorting time : %f seconds. Amount of elements : %d, Type of array :  %d", dt, n, array_key);

    free(array);
}

void test_int(void (*sort) (int* a, size_t n), size_t n, array_key array_key, bool print_arrays) {
    int * array = generate_array_int(array_key, n);
    int true_sort = 1;

    if (print_arrays) {
        printf("************** Generated array **************\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    time_t start = clock();

    sort(array, n);

    time_t end = clock();
    double dt =  (double) (end - start) / (CLOCKS_PER_SEC );

    for (int i = 1; i < n; i++) {
        if (array[i] < array[i - 1]) {
            true_sort = 0;
        }
    }

    if (print_arrays) {
        printf("************** Sorted array **************\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    if (!true_sort) {
        printf("Invalid array");
        free(array);
        return;
    }
    printf("Int array. Sorting time : %f seconds. Amount of elements : %d, Type of array :  %d", dt, n, array_key);

    free(array);
}
