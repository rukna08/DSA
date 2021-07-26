void insertion_sort(int* a, size_t s){
    for(int i = 1; i < s; i++){
        int current = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > current){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = current;
    }
}
