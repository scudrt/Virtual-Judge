#include <stdio.h>
#include <algorithm>
#define maxn 100001
struct node
{
    int a,b;
}t[maxn];
int fa[maxn],n;
bool cmp(node a,node b)
{return a.b>b.b;}
int getfa(int x)
{
    if (fa[x]!=x)
        fa[x]=getfa(fa[x]);
    return fa[x];
}
int main()
{
    while (~scanf("%d",&n))
    {
        long long ans=0;
        for (int i=1;i<=n;++i)
        {
            fa[i]=i;
            scanf("%d%d",&t[i].a,&t[i].b);
        }
        std::sort(t+1,t+n+1,cmp);
        for (int i=1;i<=n;++i)
        {
            if (t[i].a>n)
            {
                ans+=t[i].b;
                continue;
            }
            int f=getfa(t[i].a);
            if (f)
            {
                ans+=t[i].b;
                fa[f]=getfa(fa[f-1]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
