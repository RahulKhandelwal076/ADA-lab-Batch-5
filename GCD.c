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
    printf("Enter the value of a and b: ");
    scanf("%d%d",&a,&b);
    int ans = gcd(a,b);
    printf("GCD of %d and %d is: %d ",a,b,ans);
    float time = clock();
    printf("\nTime taken to complete the program is: %f", (time/CLOCKS_PER_SEC));
}
