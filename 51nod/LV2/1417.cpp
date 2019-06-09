#include <stdio.h>
int t;
long long gcd(long long a,long long b)
{
    if (!b)
        return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        long long n,m,temp;
        scanf("%lld%lld",&n,&m);
        temp=n;
        n+=m;
        m=4*n;
        n=3*n-2*temp;
        temp=gcd(n,m);
        printf("%lld/%lld\n",n/temp,m/temp);
    }
    return 0;
}
