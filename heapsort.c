#include <stdio.h>
  #include<time.h>

  clock_t start,end;
  double cpu_time_used;

  void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  void heapify(int array[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
      largest = left;

    if (right < n && array[right] > array[largest])
      largest = right;
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, n, largest);
    }
  }


  void heapSort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(array, n, i);
    for (int i = n - 1; i >= 0; i--) {
      swap(&array[0], &array[i]);
      heapify(array, i, 0);
    }
  }


  void print(int array[], int n) {
    for (int i = 0; i < n; ++i)
      printf("\nThe element at index %d is: %d", i, array[i]);
  }


  int main() {
      int n;
      clock_t t;
      double time_taken = 0.0;
      printf("\n Enter the number of elements : ");
      scanf("%d",&n);
      int array[n];
      for (int i = 0; i<n; i++){
        array[i] = rand();
      }
    print(array,n);

    t = clock();
    heapSort(array, n);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\nSorted array : ");
    print(array, n);
    printf("\nTime taken is: %f",time_taken);
  }
