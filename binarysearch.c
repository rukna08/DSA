#include <stdio.h>

int binarysearch(int* arr, int low, int high, int target) {
    int mid = (low + high) / 2;

    if(arr[mid] == target) {
        return mid;
    } else if(target > arr[mid]) {
        return binarysearch(arr, mid + 1, high, target);
    } else {
        return binarysearch(arr, low, mid - 1, target);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = size - 1;

    int target = 9;

    printf("target index: %d", binarysearch(arr, low, high, target));

    return 0;
}