#include <cstdio>
#include <algorithm>
struct node
{
    int v,a,b;
    bool operator <(const node&)const;
    bool operator ==(const node&)const;
    bool operator !=(const node&)const;
}t[500001];
int a[1001],n;
bool yes=false;
bool node::operator <(const node& x)const
{
    return v < x.v;
}
bool node::operator ==(const node& x)const
{
    if (a==x.a || a==x.b || b==x.a || b==x.b)
        return true;
    return false;
}
bool node::operator !=(const node& x)const
{
    if (a==x.a || a==x.b || b==x.a || b==x.b)
        return false;
    return true;
}
void preDeal()
{
    for (int i=1;i<n;++i)
        for (int j=i+1;j<=n;++j)
        {
            t[++t[0].v].v=a[i]+a[j];
            t[t[0].v].a=i;
            t[t[0].v].b=j;
        }
}
void deal()
{
    for (int i=1;t[i].v<=0;++i)
    {
        int l=1,r=n,mid;
        while (l<r)
        {
            mid=(l+r)>>1;
            if (t[mid].v+t[i].v<0)
                l=mid+1;
            else
                r=mid;
        }
        if (t[l].v+t[i].v==0)
        {
            if (t[l]==t[i]) //prevent selecting the same element(s)
            {
                int j=l+1;
                while (t[j].v==t[j-1].v && t[j]==t[i])
                    ++j;
                if (t[j].v==t[j-1].v && t[j]!=t[i])
                {
                    yes=true;
                    return;
                }
            }
            else
            {
                yes=true;
                return;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    preDeal();
    n=t[0].v;
    std::sort(t+1,t+n+1);
    deal();
    if (yes)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
