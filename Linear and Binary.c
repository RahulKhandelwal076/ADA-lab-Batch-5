#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void linear_search(int key,int array[100],int n)
    {
        int i,index;
        for(i=1;i<=n;i++)
        {
            if(key == array[i])
            {
                index = i;
                printf("Index of key: %d\n",index-1);
        }
    }
}

void binary_search(int key,int array[100],int n)
{
    int mid,i,first,last;
    first = 1;
    last = n;
    mid = ( first + last)/2;
    i=1;
    while(key != array[mid])
    {
        if(key <= array[mid])
        {
            first = 1;
            last = mid+1;
            mid = (first+last)/2;
        }
        else
        {
            first = mid+1;
            last = n;
            mid = (first+last)/2;
        }

}

    printf("Index of key =%d\t",mid-1);

}


int main()
{
    int array[100],key,i,n,index,choice;
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Enter the key:");
    scanf("%d",&key);
    printf("1.Linear search\n");
    printf("2.Binary search\n");
    printf("3.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        linear_search(key,array,n);
        break;
    case 2:
        binary_search(key,array,n);
        break;
    case 3:
        exit(0);

    }
        float time = clock();
        printf("\nTime taken to finish the program is: %f seconds",(time/CLOCKS_PER_SEC));
}




