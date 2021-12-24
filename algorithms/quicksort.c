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