#include <stdio.h>

void printarray(int* arr, int size) {
    printf("\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main(){
    int arr[] = {1,1,1,1,1,1};
    printarray(arr, 6);

    return 0;
}