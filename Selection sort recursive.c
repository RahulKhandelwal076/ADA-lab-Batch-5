#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int arr[],int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[],int index, int arrLen)
{
    int minimum = index;
    for(int j = minimum+1; j<arrLen;j++ ){
        if(arr[j]<arr[minimum]){
            minimum = j;
        }
    }
    swap(arr,minimum,index);
    if(index+1 < arrLen){
        selectionSort(arr,index+1,arrLen);
    }
}

int main()
{
    int size;
    clock_t t;
    double time_taken = 0.0;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i<size; i++){
        arr[i] = rand();
    }
    for(int i = 0; i<size; i++){
        printf("\nThe element at index %d in unsorted array is: %d",i,arr[i]);
    }
    int arrLen = sizeof(arr)/sizeof(arr[0]);
    t = clock();
    selectionSort(arr,0,arrLen);
    t = clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    for(int i = 0; i<size; i++){
        printf("\n\nThe element at index %d in sorted array is: %d",i,arr[i]);
    }
    printf("\n\n\nTime taken by selection sort is: %f",time_taken);
}
