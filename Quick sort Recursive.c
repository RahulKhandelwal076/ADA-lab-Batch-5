#include<stdio.h>
#include <time.h>

void quicksort(int *arr, int low, int high)
{
    int pivot, i, j, temp;
    if(low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while(i < j)
        {
            while(arr[i] <= arr[pivot] && i <= high)
            i++;
            while(arr[j] > arr[pivot] && j >= low)
            j--;
            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    quicksort(arr, low, j-1);
    quicksort(arr, j+1, high);
  }
}

int main()
{
    int size, i;
    clock_t t;
    double time_taken = 0.0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    for(i = 0; i<size;i++)
        {
            arr[i] = rand();
        }

    /*for(i = 0; i<size; i++)
        {
            printf("Random elements in unsorted array at index %d is: %d\n ",i,arr[i]);
        }*/
    t = clock();
    quicksort(arr, 0, size-1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n");

    for(i = 0; i < size; i++)
        {
            printf("Random element at index %d in sorted array is: %d \n",i,arr[i]);
        }

    printf("Time taken by quick sort is: %f seconds",time_taken);


  return 0;
}

