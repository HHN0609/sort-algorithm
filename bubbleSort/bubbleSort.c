#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 6

void bubbleSort(int *arr, int length);
void output(int *arr, int length);

int main () {
    int arr[ARR_SIZE] = {1, 2, 3, 0, 5, 6};
    bubbleSort(arr, ARR_SIZE);
    output(arr, ARR_SIZE);
    return 0;
}

void output(int *arr, int length){
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int length){
    int has_Swap = 0;
    for (int i = length-1; i>=1; i--){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                has_Swap = 1;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!has_Swap) return;
        has_Swap = 0;
    }
}