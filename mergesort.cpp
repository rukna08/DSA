void merge(int* a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int a1[n1];
    int a2[n2];

    for (int i = 0; i < n1; i++){
        a1[i] = a[l + i];
    }

    for (int j = 0; j < n2; j++){
        a2[j] = a[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) {
            a[k] = a2[i];
            i++;
        }
        else {
            a[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = a1[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = a2[j];
        j++;
        k++;
    }
}

void merge_sort(int* a, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);

        merge(a, l, m, r);
    }
}
