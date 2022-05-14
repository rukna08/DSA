#include <stdio.h>

void quicksort(int* arr, int indexOfFirstElement, int indexOfLastElement) {
    if(indexOfFirstElement < indexOfLastElement) {
        int pivot = indexOfLastElement;

        int i = indexOfFirstElement - 1;
        
        for(int j = indexOfFirstElement; j < indexOfLastElement; j++) {
            if(arr[j] <= arr[pivot]) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[pivot];
        arr[pivot] = arr[i + 1];
        arr[i + 1] = temp;

        quicksort(arr, indexOfFirstElement, pivot - 1);
        quicksort(arr, pivot + 1, indexOfLastElement);
    }
}

int main() {
    int arr[] = {7, 2, 1, 8, 6, 3, 5, 4};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, size - 1);
    
    for(int i = 0; i < size; i++) printf("%d\n", arr[i]);

    return 0;
}