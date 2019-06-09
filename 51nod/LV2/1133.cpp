#include <cstdio>
#include <algorithm>
struct node
{
    int l,r;
    bool operator <(const node&)const;
}t[10001];
bool node::operator <(const node& x)const
{
    if (r==x.r)
        return l>x.l;
    return r<x.r;
}
int n,ans;
void deal()
{
    t[0].r=0x80000000;
    for (int i=1;i<=n;++i)
    {
        if (t[i].r==t[i-1].r || t[i].l<t[i-1].r)
            t[i]=t[i-1];
        else
            ++ans;
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&t[i].l,&t[i].r);
    std::sort(t+1,t+n+1);
    deal();
    printf("%d\n",ans);
    return 0;
}
