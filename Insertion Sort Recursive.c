#include <stdio.h>
#include <time.h>

void sorting(int arr [], int size)
{
    if(size <= 1)
    {
        return;
    }
    sorting(arr,size-1);
    int last = arr[size-1];
    int j = size - 2;
    while(j>=0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;

}
int main()
{
    int size;
    clock_t t;
    double time_taken = 0.0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i<size;i++)
        {
            arr[i] = rand();
        }
    for(int i = 0; i<size; i++)
        {
            printf("\nThe element at index %d in unsorted array is: %d",i,arr[i]);
        }
    t = clock();
    sorting(arr,size);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    for(int i =0; i<size; i++)
    {
        printf("\n The element at index %d after sorting is: %d",i,arr[i]);
    }

    printf("\n\nTime taken for insertion sort is: %f seconds",time_taken);

}
