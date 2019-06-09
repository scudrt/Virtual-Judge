#include <stdio.h>
#include <algorithm>
int n,m,ans,fa[1001];
struct node
{
    int from,to,val;
    bool operator <(const node&)const;
}t[50001];
bool node::operator<(const node& x)const
{
    return val<x.val;
}
int getfa(int x)
{
    if (fa[x]!=x)
        fa[x]=getfa(fa[x]);
    return fa[x];
}
void deal()
{
    int top=0;
    for (int i=1;i<n;++i)
    {
        while (1)
        {
            ++top;
            if (getfa(t[top].from)!=getfa(t[top].to))
            {
                fa[getfa(t[top].from)]=t[top].to;
                ans+=t[top].val;
                break;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
        scanf("%d%d%d",&t[i].from,&t[i].to,&t[i].val);
    for (int i=1;i<=n;++i)
        fa[i]=i;
    std::sort(t+1,t+m+1);
    deal();
    printf("%d\n",ans);
    return 0;
}
