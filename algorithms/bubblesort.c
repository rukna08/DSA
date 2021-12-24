void bubblesort(int* arr, int sizeofarr){
    for(int i = 0; i < sizeofarr; i++) {
        for(int j = 0; j < sizeofarr-i-1; j++) {
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}