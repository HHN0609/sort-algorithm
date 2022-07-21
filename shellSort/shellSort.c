#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 6

void shellSort (int *arr, int length);
void outputArr(int *arr, int length);

int main (){
    int arr[ARR_SIZE] = {9, 0, -1, 49, 20, 39};
    shellSort(arr, ARR_SIZE);
    return 0;
}

void outputArr(int *arr, int length){
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shellSort(int *arr, int length){
    int d = length / 2;
    while (d != 0){
        for(int i=d; i<length; i++){
            // 已经有序，就直接跳出循环
            if(arr[i] >= arr[i-d]) continue;

            int temp = arr[i];
            int j;
            for(j=i-d; j>=0; j=j-d){
                if(arr[j] > temp){
                    arr[j+d] = arr[j];
                } else {
                    break;
                }
            }
            arr[j+d] = temp;
        }
        outputArr(arr, length);
        d = d / 2;
    }
}
