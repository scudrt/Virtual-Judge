#include <cstdio>
#define min(a,b) (a>b?b:a)
int a[50001],w[50001]={0x7fffffff},n,m,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&w[i]);
        w[i]=min(w[i],w[i-1]);
    }
    for (int i=1;i<=m;++i)
        scanf("%d",&a[i]);
    int now=n;
    for (int i=1;i<=m;++i)
    {
        while (a[i]>w[now] && now)
            --now;
        if (!now)
            break;
        --now;
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
