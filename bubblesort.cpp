#include <iostream>

void printarray(int* arr, int n) {
    for (int i = 0; i < n; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubblesort(int* arr, int sizeofarr){
    for(int i = 0; i < sizeofarr; i++) {
        for(int j = 0; j < sizeofarr-i; j++) {
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {5,4,7,2,1};
    int sizeofarr = sizeof(arr)/sizeof(int);
    printarray(arr, sizeofarr);
    bubblesort(arr, sizeofarr);
    printarray(arr, sizeofarr);
}