#include <stdio.h>
#include <algorithm>
#define maxn 50000+1
int n,f[maxn],a[maxn],list[maxn];
long long ans,s;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        while (a[list[list[0]]]>=a[i])
            --list[0];
        f[i]=i-list[list[0]]-1;
        list[++list[0]]=i;
    }
    list[0]=0;
    for (int i=n;i>=1;--i)
    {
        while (a[list[list[0]]]>=a[i])
            --list[0];
        if (list[0])
            f[i]+=list[list[0]]-i;
        else
            f[i]+=n-i+1;
        list[++list[0]]=i;
        s=(long long)a[i]*f[i];
        ans=std::max(ans,s);
    }
    printf("%lld\n",ans);
    return 0;
}
