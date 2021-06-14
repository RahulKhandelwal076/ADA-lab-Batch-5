#include <stdio.h>
#include <time.h>

void merge_sort(int i, int j, int a[], int aux[])
{
    if (j <= i) {
        return;
    }
    int mid = (i + j) / 2;
    merge_sort(i, mid, a, aux);
    merge_sort(mid + 1, j, a, aux);
    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }
    for (k = i; k <= j; k++) {
        a[k] = aux[k];
    }
}
int main()
{
    int n, i, d, swap;
    clock_t t;
    double time_spent = 0.0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n], aux[n];
    printf("The integers are: \n");
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        printf("%d\n",a[i]);
    }
    clock_t begin = clock();
    merge_sort(0, n - 1, a, aux);
    t = clock() - t;
    printf("Printing the sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    t = clock();
    time_spent = ((double)t)/ CLOCKS_PER_SEC;
    printf("\nExecution Time : %f seconds\n", time_spent);
    return 0;
}
