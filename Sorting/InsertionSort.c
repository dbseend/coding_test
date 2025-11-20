// Insertion Sort
void insertionSort(int* arr, int len){
    for(int i=1; i<len; i++){
        if(arr[i-1] < arr[i]) continue;
        int key = arr[i];

        for(int j=0; j<i; j++){
            if(arr[j] > key){
                for(int k=i; k>j; k--){
                    arr[k] = arr[k-1];
                }
                arr[j] = key;
                break;
            }
        }
    }
}