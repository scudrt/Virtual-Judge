#include <stdio.h>
#include <algorithm>
#define maxn 50000+1
int n,f[maxn];
long long ans;
struct node
{
    int w,v;
    bool operator <(const node&)const;
}t[maxn];
bool node::operator <(const node& x)const
{return v<x.v;}
int getfa(int x)
{
    if (f[x]!=x)
        f[x]=getfa(f[x]);
    return f[x];
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        f[i]=i;
        scanf("%d%d",&t[i].w,&t[i].v);
    }
    std::sort(t+1,t+n+1);
    for (int i=n;i>=1;--i)
    {
        if (t[i].w>n)
            ans+=t[i].v;
        else
        {
            int fa=getfa(t[i].w);
            if (fa==0)
                continue;
            else
            {
                f[fa]=getfa(f[fa-1]);
                ans+=t[i].v;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
