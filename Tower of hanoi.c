#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void tower(int n, char a, char b, char c)
{
    if(n>0)
        {
            tower(n-1, a, c, b);
            printf("\n Move a disk from %c to %c", a,c);
            tower(n-1,b,a,c);
        }

}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    tower(n,'A','B','C');
    float time = clock();
    printf("\nTime taken to complete the program is: %f seconds", (time/CLOCKS_PER_SEC));
}
