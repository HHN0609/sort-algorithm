#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// 荷兰军旗问题
int main () {
    int arr[SIZE] = {0, 2, 1, 2, 0, 0, 0, 2, 1, 1};
    int i = 0;
    int p0 = 0;
    int p1 = SIZE - 1;
    while (i <= p1)
    {
        if(arr[i] == 0)
        {
            swap(arr, i, p0);
            p0++;
        }
        if(arr[i] == 2)
        {
            swap(arr, i, p1);
            p1--;
            i--;
        }
        i++;
    }
    for(int i=0; i<SIZE; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}