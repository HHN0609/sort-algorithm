#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
// 递归版本
void heapify(int *arr, int length, int index);
void buildHeap(int *arr, int length);
void heapSort(int *arr, int length);

int main() {
    int arr[SIZE] = {8, 9, -10, 3, 9, 28, -90, 23, 32, 0};
    heapSort(arr, SIZE);
    for(int i=0; i<SIZE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void heapify(int *arr, int length, int index){
    // 叶子节点，退出递归
    if(index >= length / 2) return;
    int left = index * 2 + 1;
    int right = left + 1;
    int max = index;
    if(left < length && arr[max] < arr[left]){
        max = left;
    }
    if(right < length && arr[max] < arr[right]){
        max = right;
    }
    if(max != index){
        int temp = arr[max];
        arr[max] = arr[index];
        arr[index] = temp;
        heapify(arr, length, max);
    }
    return;
}

void buildHeap(int *arr, int length){
    // p是最后一个非叶子节点的下标
    int p = length / 2 - 1;
    while (p >= 0){
        heapify(arr, length, p);
        p--;
    }
    return;
}


void heapSort(int *arr, int length){
    buildHeap(arr, length);
    for(int i=0; i<length - 1; i++){
        int temp = arr[0];
        arr[0] = arr[length - i - 1];
        arr[length - i - 1] = temp;
        heapify(arr, length - i - 1, 0);
    }
    return;
}






