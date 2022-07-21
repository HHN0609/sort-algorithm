#include <stdlib.h>
#include <stdio.h>
#define ARR_SIZE 6

void quickSort(int *arr, int length);
void sort(int *arr, int left, int right);

int main(){
    int arr[ARR_SIZE] = {9, -10, 4, 2, 9, 8};
    quickSort(arr, ARR_SIZE);
    for(int i=0; i<ARR_SIZE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void quickSort(int *arr, int length){
    sort(arr, 0, length - 1);
}

// [left, right]
void sort(int *arr, int left, int right){
    if(left >= right) return;
    int _left = left;
    int _right = right;
    int pVoite = arr[left];
    while (left < right){
        while(arr[right] >= pVoite && left < right){
            right--;
        }
        arr[left] = arr[right];

        while(arr[left] <= pVoite && left < right){
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pVoite;
    sort(arr, _left, left - 1);
    sort(arr, left + 1, _right);
}