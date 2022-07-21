#include <stdio.h>
#include <stdlib.h>
#define ARR_SZIE 2

void insertSort(int *, int);

int main() {
    int arr[ARR_SZIE] = {8, 0};
    insertSort(arr, ARR_SZIE);
    for(int i=0; i<ARR_SZIE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

// 排序后的结果为升序
void insertSort(int *arr, int length){
    for(int i=1; i<length; i++){
        // 如果arr[i]比arr[i-1]要大，那么就跳过本次循环
        if(arr[i-1] <= arr[i]) continue;

        int j;
        int temp = arr[i]; // temp是待插入的值
        for(j=i-1; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        // 这里要注意是什么位置放temp;
        arr[j + 1] = temp;
    }
}