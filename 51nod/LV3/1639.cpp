#include <stdio.h>
#define mod 1000000
double ans=mod;
int n;
int main()
{
    scanf("%d",&n);
    while (n!=1)
    {
        ans=ans*(n+n-2)/(n+n-1);
        --n;
    }
    printf("%.6llf\n",ans/mod);
    return 0;
}
