#include <iostream>

void printarray(int *arr, int n) {
    for (int i = 0; i < n; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void quicksort(int *arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(i + j) / 2];
    int temp;

    while (i <= j) {
        while (arr[i] < pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }

        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (j > left){
        quicksort(arr, left, j);
    }
    if (i < right){
        quicksort(arr, i, right);
    }
}

int main() {
    int arr[] = {500, 1, 25, 27, 3, 597, 39};
    int sizeofarr = sizeof(arr)/sizeof(int);

    printarray(arr, sizeofarr);

    quicksort(arr, 0, sizeofarr);

    printarray(arr, sizeofarr);
    
    return (0);
}