#include <stdio.h>
#define mod 1000000007
int n,f[1000001]={1,1};
int main()
{
    scanf("%d",&n);
    for (int i=2;i<=n;++i)
    {
        if (!(i&1))
            f[i]=f[(i>>1)];
            f[i]=(f[i]+f[i-1])%mod;
    }
    printf("%d\n",f[n]);
    return 0;
}
