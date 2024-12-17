#include "sort.h"

#include <stdio.h>
#include <stdlib.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void merge(double *left_arr, int ln, double *right_arr, int rn, double* arr) {
    int i = 0, l = 0, r = 0;
    while (l < ln && r < rn) {
        if (left_arr[l] <= right_arr[r]) {
            arr[i] = left_arr[l];
            i++;
            l++;
        }
        else {
            arr[i] = right_arr[r];
            i++;
            r++;
        }
    }
    while (l < ln) {
        arr[i] = left_arr[l];
        i++;
        l++;
    }
    while (r < rn) {
        arr[i] = right_arr[r];
        i++;
        r++;
    }
    free(left_arr);
    free(right_arr);
}

void merge_sort(double *arr, int n) {
    if (n <= 1) {
        return;
    }
    int mid = n / 2;
    double * left_array = (double *) malloc(sizeof(double) * mid);
    double * right_array = (double *) malloc(sizeof(double) *(n - mid));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i < mid) {
            left_array[i] = arr[i];
        }
        else {
            right_array[j]  = arr[i];
            j++;
        }
    }
    merge_sort(left_array, mid);
    merge_sort(right_array, n - mid);
    merge(left_array, mid, right_array, n - mid, arr);
}



void bubble_sort(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selection_sort(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
            swap(&arr[min], &arr[i]);
        }
    }
}

void insertion_sort(double *arr, int n) {
    for (int i = 1; i < n; i++) {
        double x = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > x) {
            arr[j] = arr[j-1];
            j -= 1;
        }
        arr[j] = x;
    }
    // for (int i = 1; i != n; ++i) {
    //     double key = arr[i];
    //     int j = i - 1;
    //
    //     while (j >= 0 && arr[j] > key) {
    //         swap(&arr[j], &arr[j + 1]);
    //         --j;
    //     }
    //     arr[j + 1] = key;
    // }

}

int partition_l(double *arr, int start, int end) {
    double pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }

    i++;
    swap(&arr[i], &arr[end]);
    return i;

}

int partition_h(double *arr, int start, int end) {
    int mid = (start + end) >> 1;
    double pivot = arr[mid];
    int i = start;
    int j = end;

    while (i <= j) {
        while (arr[i] < pivot)
            ++i;
        while (arr[j] > pivot)
            --j;
        if (i >= j)
            break;
        swap(&arr[i], &arr[j]);
        ++i;
        --j;
    }
    return j;

}

void quick_sort(double *arr, int start, int end) {

    if (end <= start) return;

    int pivot = partition_l(arr, start, end);
    quick_sort(arr, start, pivot - 1);
    quick_sort(arr, pivot + 1, end);

    // if (end - start <= 1) return;
    // while (start < end) {
    //     int q = partition_h(arr, start, end);
    //     if (q - start < end - q) {
    //         quick_sort(arr, start, q - 1);
    //         start = q + 1;
    //     }
    //     else {
    //         quick_sort(arr, q + 1, end);
    //         end = q - 1;
    //     }
    // }
}

void counting_sort(int *arr, size_t n)
{
    int i;
    int p = 0;
    int min = 2e9;
    int max = -2e9;
    for (i = 0; i < n; ++i)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int* auxArr = (int*) malloc((max - min + 1) * sizeof(int));
    for (i = 0; i <= max - min; ++i)
        auxArr[i] = 0;
    for (i = 0; i < n; ++i)
        ++auxArr[arr[i] - min];

    for (i = 0; i <= max - min; ++i)
    {
        while (auxArr[i]--)
        {
            arr[p++] = min + i;
        }
    }

    free(auxArr);
}
