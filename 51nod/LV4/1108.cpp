#include <stdio.h>
#include <algorithm>
int x[10001],y[10001],z[10001],n;
long long ans;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    std::sort(x+1,x+n+1);
    std::sort(y+1,y+n+1);
    std::sort(z+1,z+n+1);
    x[0]=x[(n+1)/2];
    y[0]=y[(n+1)/2];
    z[0]=z[(n+1)/2];
    for (int i=1;i<=(n+1)/2;++i)
    {
        ans+=x[0]-x[i];
        ans+=y[0]-y[i];
        ans+=z[0]-z[i];
    }
    for (int i=(n+1)/2+1;i<=n;++i)
    {
        ans+=x[i]+y[i];
        ans+=z[i]-x[0];
        ans-=y[0]+z[0];
    }
    printf("%lld\n",ans);
    return 0;
}
