#include <stdio.h>

void printarray(int* arr, size_t sizeofarr){
    for(size_t i = 0; i < sizeofarr; i++){
        printf("%d ", arr[i]);
    }
}

void quicksort(int* arr, size_t sizeofarr){
    int pivot = sizeofarr - 1;
    int i = -1;
    int j = 1;
    for(size_t k = 0; k < sizeofarr; k++){
        if(arr[j] < arr[pivot]) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            j++;
        } else {
            j++;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
}

int main(){
    int arr[] = {7, 2, 1, 8, 6, 3, 5, 4};
    size_t sizeofarr = sizeof(arr)/sizeof(int);

    printarray(arr, sizeofarr);
    quicksort(arr, sizeofarr);
    printarray(arr, sizeofarr);

    return 0;
}