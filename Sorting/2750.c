// 문제
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

// 출력
// 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

// 예제 입력 1 
// 5
// 5
// 2
// 3
// 4
// 1
// 예제 출력 1 
// 1
// 2
// 3
// 4
// 5
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int len);
void insertionSort(int* arr, int len);
void quickSort(int* arr, int len);
void swap(int* a, int* b);

int main(){
    int* arr;
    int len = 0;

    scanf("%d", &len);
    arr = malloc(sizeof(int)*len);

    for(int i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    // bubbleSort(arr, len);
    insertionSort(arr,len);

    for(int i=0; i<len; i++){
        printf("%d\n", arr[i]);
    }
    // for(int i=0; i<len; i++){
    //     printf("%d ", arr[i]);
    // }

    return 0;
}

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

// Quick Sort
void quickSort(int* arr, int len){

}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}