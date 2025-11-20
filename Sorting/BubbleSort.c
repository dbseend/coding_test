// Bubble Sort
void bubbleSort(int* arr, int len){
    int isSorted = 1; // 0=정렬 미완료, 1=정렬 완료
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1-i; j++){
            if(arr[j] > arr[j+1]){
                isSorted = 0;
                swap(&arr[j], &arr[j+1]);
            }
        }
    if(isSorted) break;
    }
}