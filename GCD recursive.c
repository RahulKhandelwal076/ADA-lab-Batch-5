#include <stdio.h>
#include <time.h>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    int a,b;
    clock_t start,end;
    double time_taken = 0.0;
    printf("Enter the value of a and b: ");
    scanf("%d%d",&a,&b);
    start = clock();
    int ans = gcd(a,b);
    end = clock();
    printf("GCD of %d and %d is: %d ",a,b,ans);
    time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken to complete the program is: %f seconds", time_taken);
}
