#include <stdio.h>
#define mod 100000
int t,n,k;
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&k);
        int ans=1;
        for (int i=n;i>=2;--i)
        {
            ans*=i;
            while (ans%10==0)
                ans/=10;
            ans%=mod;
        }
        for (int i=1;i<k;++i)
            ans/=10;
        ans%=10;
        printf("%d\n",ans);
    }
    return 0;
}
