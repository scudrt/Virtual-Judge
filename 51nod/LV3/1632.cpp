#include <stdio.h>
#define mod 1000000007
int n;
long long deal()
{
    long long temp=2,s=1;
    int k=n-2;
    while (k)
    {
        if (k&1)
            s=s*temp%mod;
        temp=(temp*temp)%mod;
        k=k>>1;
    }
    s=s*(n+1)%mod;
    return s;
}
int main()
{
    scanf("%d",&n);
    printf("%lld\n",deal());
    return 0;
}
