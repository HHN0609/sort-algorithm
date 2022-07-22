#include<stdlib.h>
#include<stdio.h>
#define SIZE 6
// 堆排序非递归版本
void heapSort(int *arr, int length);
void heapAdjust(int *arr, int index, int length);
void swap(int *arr, int a, int b);

int main(){
    int arr[SIZE] = {4, 59, -10, 3, 3, 3};
    heapSort(arr, SIZE);

    for(int i=0; i<SIZE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void heapSort(int *arr, int length){
    //先建堆, 大根堆
    for(int i=SIZE / 2 - 1; i>=0; i--){
        heapAdjust(arr, i, length);
    }
    // 破坏堆，重建堆
    for(int i=0; i<length - 1; i++){
        swap(arr, 0, length - i - 1);
        heapAdjust(arr, 0, length - i - 1);
    }
    return;
}

void heapAdjust(int *arr, int index, int length){
    while (index < length){
        int left = index * 2 + 1;
        int right = left + 1;
        int max = index;
        if(left < length && arr[left] > arr[max]){
            max = left;
        }
        if(right < length && arr[right] > arr[max]){
            max = right;
        }
        if(max != index){
            swap(arr, max, index);
            index = max;
        } else {
            break;
        }
    }
    return;
}

void swap(int *arr, int a, int b){
    int temp = *(arr + a);
    *(arr + a) = *(arr + b);
    *(arr + b) = temp;
    return;
}

