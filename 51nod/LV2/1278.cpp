//O(nlogn) sort and find
#include <cstdio>
#include <algorithm>
int n,ans;
struct node
{
    int l,r;
    bool operator <(const node&)const;
}t[50001];
bool node::operator <(const node& x)const
{
    return l<x.l;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int pos,r;
        scanf("%d%d",&pos,&r);
        t[i].l=pos-r;
        t[i].r=pos+r;
    }
    std::sort(t+1,t+n+1);
    for (int i=1;i<n;++i)
    {
        int l=1,r=n,mid;
        while (l<r)
        {
            mid=(l+r)>>1;
            if (t[mid].l<=t[i].r)
                l=mid+1;
            else
                r=mid;
        }
        if (t[l].l>t[i].r)
            ans+=n-l+1;
    }
    printf("%d\n",ans);
    return 0;
}
