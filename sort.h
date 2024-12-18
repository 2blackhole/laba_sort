#pragma once
#include <stdlib.h>

//utils for sort
struct bucket
{
    int count;
    int* values;
};


#define BYTE_SIZE 8
#define LONGWORD_SIZE 4
#define ARRAY_SIZE 256


void swap(double* i, double* j);

int partition_l(double *arr, int start, int end);

int partition_h(double *arr, int start, int end);

int max_int(int* arr, size_t n);

int compare_int(const void* first, const void* second);


//sorts
void bubble_sort(double *arr, int size);

void selection_sort(double *arr, int size);

void insertion_sort(double *arr, int size);

void merge_sort(double *arr, int n);

void merge(double *left_arr, int ln, double *right_arr, int rn, double* arr);

void quick_sort(double *arr, int start, int end);

void counting_sort(int *arr, size_t n);

void radix_sort(unsigned int *m, size_t length);

void bucket_sort(int *arr, size_t n);
