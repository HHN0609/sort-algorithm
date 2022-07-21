#include <stdlib.h>
#include <stdio.h>
#define ARR_SIZE 10

// [left, mid), [mid, right)
void merge(int *arr, int left, int mid, int right){
    int *temp = (int *)calloc(right - left, sizeof(int));
    int _left = left;
    int k = mid;
    int count = 0;
    while(left < mid && k < right){
        if(arr[left] < arr[k]){
            temp[count++] = arr[left];
            left++;
        } else {
            temp[count++] = arr[k];
            k++;
        }
    }
    while(left < mid){
        temp[count++] = arr[left++];
    }
    while(k < right){
        temp[count++] = arr[k++];
    }
    for(int i=0; i<count; i++){
        arr[_left+i] = temp[i];
    }
    free(temp);
    return;
}

// [left, right)
void mergeSort(int *arr, int left, int right) {
    if(left >= right - 1) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, left, mid, right);
    return;
}

int main(){
    int arr[ARR_SIZE] = {9, 2, 20, -10, 3, 4, 5, 29, 29, -10};
    mergeSort(arr, 0, ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}