#include <stdio.h>
#include <stdlib.h>

int *sorted; 

void swap(int* a, int* b);

void merge(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int left, int right);

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int left, int mid, int right) {

    int i = left;
    int j = mid+1;
    int k = left; // 임시 배열의 인덱스

    while(i <= left && j <= right){
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

    for(int l = left; l < right; l++){
        arr[l] = sorted[l];
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right){
        int mid = (left+right)/2;

        mergeSort(arr ,left, mid);
        mergeSort(arr ,mid+1, right);

        merge(arr, left, mid, right);
    }
}