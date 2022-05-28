#include <stdio.h>

void bubblesort(int* arr, size_t size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {99, 11, 555, 2, 1234};

    size_t size = sizeof(arr) / sizeof(arr[0]);

    bubblesort(arr, size);

    for(int i = 0; i < size; i++) printf("%d\n", arr[i]);

    return 0;
}