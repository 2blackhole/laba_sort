#pragma once
#include <stdlib.h>

void bubble_sort(double *arr, int size);

void selection_sort(double *arr, int size);

void insertion_sort(double *arr, int size);

void swap(double* i, double* j);

void merge_sort(double *arr, int n);

void merge(double *left_arr, int ln, double *right_arr, int rn, double* arr);

void quick_sort(double *arr, int start, int end);

int partition_l(double *arr, int start, int end);

int partition_h(double *arr, int start, int end);

void counting_sort(int *arr, size_t n);