#include <cstdio>
#define mod2 2000000014
#define mod 1000000007
int n,ans;
void deal()
{
    ++n;
    long long sum=1,now=3;
    while (n)
    {
        if (n&1)
            sum=(sum*now)%mod2;
        now=(now*now)%mod2;
        n=n>>1;
    }
    if (!sum)
        sum+=mod;
    ans=((sum-1)>>1)%mod;
}
int main()
{
    scanf("%d",&n);
    deal();
    printf("%d\n",ans);
    return 0;
}
