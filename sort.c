#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

int max_int(int* arr, size_t n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
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
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_i]) {

                min_i = j;
            }
        }

        swap(&arr[i], &arr[min_i]);
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

    if (start >= end) return;

    int pivot = partition_h(arr, start, end);
    quick_sort(arr, start, pivot);
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
    // int max = max_int(arr, n);
    //
    // int* a = (int*)malloc(sizeof(int) * max + 1);
    //
    // for (int i = 0; i <= max; i++) {
    //     a[i] = 0;
    // }
    //
    // for (int i = 0; i < n; i++) {
    //     a[arr[i]]++;
    // }
    //
    // int j = 0;
    // for (int i = 0; i <= max; i++) {
    //     while (a[i] > 0) {
    //         arr[j++] = i;
    //         a[i]--;
    //     }
    // }
    //
    // free(a);
}

// void radix_sort(int* arr, size_t n) {
//     // int max = max_int(arr, n);
//     // int auxArr[10];
//     //
//     // int i = 0;
//     // while (max / (i * 10) != 0);
//     //IN PROGRESS
// }



int compare_int(const void* first, const void* second)
{
    int a = *((int*)first), b =  *((int*)second);
    if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void bucket_sort(int* arr, size_t n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * n);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            buckets[0].values[buckets[0].count++] = arr[i];
        }
        else if (arr[i] > 10)
        {
            buckets[2].values[buckets[2].count++] = arr[i];
        }
        else
        {
            buckets[1].values[buckets[1].count++] = arr[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        qsort(buckets[i].values, buckets[i].count, sizeof(int), &compare_int);
        for (j = 0; j < buckets[i].count; j++)
        {
            arr[k + j] = buckets[i].values[j];
        }
        k += buckets[i].count;
        free(buckets[i].values);
    }
}

void sort_step(unsigned int *source, unsigned int *dest, unsigned int *offset, int num, size_t length) {
    int i;
    unsigned int temp;
    unsigned char k;
    for (i = length - 1; i >= 0; i--) {
        temp = source[i];
        k = (temp >> num) & 0xFF;
        offset[k]--;
        dest[offset[k]] = temp;
    }
}

void radix_sort(unsigned int *m, size_t length) {
    unsigned int s[LONGWORD_SIZE][ARRAY_SIZE] = {0};
    unsigned int *m_temp = (unsigned int *)malloc(length * sizeof(unsigned int));
    unsigned int i, k;
    unsigned int offset[LONGWORD_SIZE][ARRAY_SIZE] = {0};

    for (i = 0; i < length; i++) {
        k = m[i];
        s[0][(k >> 0) & 0xFF]++;
        s[1][(k >> 8) & 0xFF]++;
        s[2][(k >> 16) & 0xFF]++;
        s[3][(k >> 24) & 0xFF]++;
    }

    for (i = 1; i < ARRAY_SIZE; i++) {
        s[0][i] += s[0][i - 1];
        s[1][i] += s[1][i - 1];
        s[2][i] += s[2][i - 1];
        s[3][i] += s[3][i - 1];
    }

    memcpy(offset[0], s[0], ARRAY_SIZE * sizeof(unsigned int));
    memcpy(offset[1], s[1], ARRAY_SIZE * sizeof(unsigned int));
    memcpy(offset[2], s[2], ARRAY_SIZE * sizeof(unsigned int));
    memcpy(offset[3], s[3], ARRAY_SIZE * sizeof(unsigned int));

    sort_step(m, m_temp, offset[0], 0, length);
    sort_step(m_temp, m, offset[1], 8, length);
    sort_step(m, m_temp, offset[2], 16, length);
    sort_step(m_temp, m, offset[3], 24, length);

    free(m_temp);
}