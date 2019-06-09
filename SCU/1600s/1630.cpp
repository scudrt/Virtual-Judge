#include <stdio.h>
int n,m,a;
long long ans;
long long gcd(long long a,int b)
{return (b==0?a:gcd(b,a%b));}
int main()
{
    scanf("%d",&n);
    while (n--)
    {
        ans=1;
        scanf("%d",&m);
        for (int i=1;i<=m;++i)
        {
            scanf("%d",&a);
            ans=ans*a/gcd(ans,a);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
