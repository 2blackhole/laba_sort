#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logic.h"
#include "sort.h"

int main(const int argc, char **argv) {
    if (argc != 5) {
        return -1;
    }
    if (strcmp(argv[1], "bubble_sort") == 0) {
        test_n(bubble_sort, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }
    else if (strcmp(argv[1], "selection_sort") == 0) {
        test_n(selection_sort, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }
    else if (strcmp(argv[1], "insertion_sort") == 0) {
        test_n(insertion_sort, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }
    else if (strcmp(argv[1], "merge_sort") == 0) {
        test_n(merge_sort, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }
    else if (strcmp(argv[1], "quick_sort") == 0) {
        test_se(quick_sort, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }
    else if (strcmp(argv[1], "counting_sort") == 0) {
        test_int(counting_sort, atoll(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }
    else if (strcmp(argv[1], "radix_sort") == 0) {
        test_int(radix_sort, atoll(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }
    else if (strcmp(argv[1], "bucket_sort") == 0) {
        test_int(bucket_sort, atoll(argv[2]), atoi(argv[3]), atoi(argv[4]));
    }

    return 0;
}