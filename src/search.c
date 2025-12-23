#include "search.h"
#include <string.h>

/*
===============================================================================
LINEAR SEARCH — BLACKLIST CHECK
Works on unsorted arrays
===============================================================================
Time Complexity: O(n)
Returns index if found, otherwise -1
===============================================================================
*/
int linear_search(char arr[][32], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            return i;   // found
        }
    }
    return -1;          // not found
}

/*
===============================================================================
BINARY SEARCH — BLACKLIST CHECK
Array MUST be sorted alphabetically
===============================================================================
Time Complexity: O(log n)
Returns index if found, otherwise -1
===============================================================================
*/
int binary_search(char arr[][32], int size, const char *target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0) {
            return mid;             // found
        } else if (cmp < 0) {
            left = mid + 1;         // search right half
        } else {
            right = mid - 1;        // search left half
        }
    }
    return -1;                      // not found
}
