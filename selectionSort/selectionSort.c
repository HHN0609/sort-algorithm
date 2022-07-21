#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void selectionSort(int *arr, int length);

int main(){
    int arr[SIZE] = {9, 3, 4, 10, 200, -29, 39, 9, 10, 2};
    selectionSort(arr, SIZE);
    for(int i=0; i<SIZE; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void selectionSort(int *arr, int length){
    for (int i = 0; i < length-1; i++)
    {
        int min = i;
        for(int j=i+1; j<length; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}