#include <stdio.h>



void printarray(int*, size_t);
void quicksort(int*, int, int);



int main(){
    int arr[] = {7, 2, 1, 8, 6, 3, 5, 4};
    size_t sizeofarr = sizeof(arr)/sizeof(int);
    int right = (int)(sizeofarr - 1);

    printarray(arr, sizeofarr);
    quicksort(arr, 0, right);
    printarray(arr, sizeofarr);

    return 0;
}



void printarray(int* arr, size_t sizeofarr){
    printf("\n");
    for(size_t i = 0; i < sizeofarr; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void swap(int* arr, int i1, int i2) {
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}



void quicksort(int* arr, int left, int right){
    int pivot = right;
    int i = left-1;
    int j = left;

    for(int k = 0; k < pivot; k++){
        if(arr[j] < arr[pivot]) {
            i++;
            swap(arr, i, j);
            j++;
        } else {
            j++;
        }
    }

    swap(arr, i+1, pivot);
    quicksort(arr, left, i);
    quicksort(arr, i+1, right);
}