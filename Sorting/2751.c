// https://www.acmicpc.net/problem/2751
/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

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

void swap(int* a, int* b);
void merge(int* arr, int* sorted, int left, int mid, int right);
void mergeSort(int* arr, int* sorted, int left, int right);

int main(){
    int* arr;
    int *sorted; 
    int len = 0;

    scanf("%d", &len);
    arr = malloc(sizeof(int)*len);
    sorted = malloc(sizeof(int)*len);

    for(int i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, sorted, 0, len-1);

    for(int i=0; i<len; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int* arr, int* sorted, int left, int mid, int right) {

    int i = left;
    int j = mid+1;
    int k = left; 

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            sorted[k] = arr[i];
            i++;
        } else {
            sorted[k] = arr[j];
            j++;
        }

        k++;
    }

    while(i <= mid){
        sorted[k] = arr[i];
        i++;
        k++;
    }
    while(j <= right){
        sorted[k] = arr[j];
        j++;
        k++;
    }

    for(int l = left; l <= right; l++){
        arr[l] = sorted[l];
    }
}

void mergeSort(int* arr, int* sorted, int left, int right) {
    if(left < right){
        int mid = (left+right)/2;

        mergeSort(arr ,sorted, left, mid);
        mergeSort(arr ,sorted, mid+1, right);

        merge(arr, sorted, left, mid, right);
    }
}