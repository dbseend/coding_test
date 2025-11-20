// Quick Sort
void quickSort(int* arr, int len, int left, int right){
    if(left < right){
        int index = partition(arr, len, left, right);

        quickSort(arr, len, left, index-1);
        quickSort(arr, len, index+1, right);
    }   
}

int partition(int* arr, int len, int left, int right){
    int pivotIdx = getMedianOfThree(arr, len, left, right);

    if(pivotIdx != left) swap(&arr[left], &arr[pivotIdx]);
    pivotIdx = left;
    int pivotValue = arr[pivotIdx];
    left++;

    while(left <= right){

        while(arr[left] <= pivotValue && left < right) left++;
        while(arr[right] >= pivotValue && left <= right) right--;

        if(left < right) swap(&arr[left], &arr[right]);
        else break;
    }

    swap(&arr[pivotIdx], &arr[right]);

    return right;
}

int getMedianOfThree(int* arr, int len, int left, int right) {
    int a = left;
    int b = (left+right)/2;
    int c = right;

    int l = arr[a], m = arr[b], r = arr[c];

    if ((l <= m && m <= r) || (r <= m && m <= l)) return b;
    else if ((m <= l && l <= r) || (r <= l && l <= m)) return a;
    else return c;
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}