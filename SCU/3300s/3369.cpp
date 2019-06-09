#include <stdio.h>
#include <algorithm>
#define min(a,b) ((a)>(b)?(b):(a))
#define maxn 10001
#define maxm 100001
struct node
{
    int a,b,c;
    bool operator <(const node &x)const
    {return c<x.c;}
}t[maxm];
int n,m,ans,minn,fa[maxn],c[maxn];
int getfa(int x)
{return x-fa[x]?fa[x]=getfa(fa[x]):x;}
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        ans=0;
        minn=0x7fffffff;
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&c[i]);
            minn=min(minn,c[i]);
            fa[i]=i;
        }
        ans=minn;
        --n;
        for (int i=1;i<=m;++i)
        {
            scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
            t[i].c+=t[i].c+c[t[i].a]+c[t[i].b];
        }
        std::sort(t+1,t+m+1);
        for (int i=1;i<=m && n;++i)
        {
            int x=getfa(t[i].a),y=getfa(t[i].b);
            if (x!=y)
            {
                --n;
                ans+=t[i].c;
                fa[x]=y;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
