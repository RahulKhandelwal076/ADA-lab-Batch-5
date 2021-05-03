#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[],int first, int last, int key)
{
	if(last < first){
		return -1;
	}
	if(arr[first] == key){
       return first;
	}
	return linearSearch(arr, first +1, last, key);

}



int binarySearch(int arr[], int first, int last, int key)
{
	int mid = (first + last)/2;
	if(arr[mid] == key){
		return mid;
	}
	if(key > arr[mid]){
		return binarySearch(arr, mid+1, last, key);
	}
	if(key < arr[mid]){
		return binarySearch(arr, first, mid-1,key);
	}
	return -1;
}



int main()
{
	int size,temp,key,last,arrlen,choice,result;
	clock_t start,end;
	double time_taken;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int arr[size];
	for(int i = 0; i<size; i++){
		arr[i] = rand();
	}
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++){
			if(arr[j] < arr[i]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for(int i = 0; i<size; i++){
		printf("\nThe element present at index %d is: %d",i,arr[i]);
	}
	arrlen = sizeof(arr)/sizeof(arr[0]);
	last = arrlen - 1;
	printf("\nEnter the key: ");
	scanf("%d", &key);
	printf("\nSelect the choice: \n1. Linear Search \n2. Binary Search \n3. Exit\n");
	scanf("%d",&choice);
	switch (choice){
		case 1:
                time_taken = 0.0;
                start = clock();
                result = linearSearch(arr,0,last,key);
                end = clock();
                if(result == -1){
                    printf("Element not present in the array!");
                }
                else{
                    printf("Element found at index: %d",result);
                }
                time_taken = (double)(end-start)/CLOCKS_PER_SEC;
                printf("\nTime taken for linear search is: %f",time_taken);
				break;
		case 2:
                time_taken = 0.0;
                start = clock();
                result = binarySearch(arr,0,last,key);
                end = clock();
				if(result == -1)
					printf("Element not found in the array!");
				else
					printf("Element found at index: %d",result);
					time_taken = (double)(end-start)/CLOCKS_PER_SEC;
                printf("\nTime taken for binary search is: %f",time_taken);
				break;
		case 3: exit(0);

	}
}
