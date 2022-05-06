#include <stdio.h>
#include <limits.h>

void selectionsort(int* arr, size_t size) {
    for(int i = 0; i < size; i++) {
        int lowest = INT_MAX;
        int lowestIndex;

        for(int j = i; j < size; j++) {
            if(arr[j] < lowest) {
                lowest = arr[j];
                lowestIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = lowest;
        arr[lowestIndex] = temp;
    }
}

int main() {
    int arr[] = {55, 22, 11, 99, 56, 78, 2, 548};

    size_t size = sizeof(arr) / sizeof(int);

    selectionsort(arr, size);

    for(int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}