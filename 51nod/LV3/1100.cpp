#include <stdio.h>
#include <algorithm>
#define maxn 10000+1
int n;
double used[maxn],k;
struct node
{
    double x,y;
    int rank;
    bool operator <(const node&)const;
}t[maxn];
bool node::operator <(const node& temp)const
{
    return x < temp.x;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%lf%lf",&t[i].x,&t[i].y);
        t[i].rank=i;
    }
    std::sort(t+1,t+n+1);
    for (int i=1;i<n;++i)
    {
        double tempk=(t[i+1].y-t[i].y)/(t[i+1].x-t[i].x);
        if (tempk>k)
            used[i]=used[i+1]=k=tempk;
    }
    for (int i=1;i<n;++i)
    {
        if (used[i]==k)
        {
            printf("%d %d\n",t[i].rank,t[i+1].rank);
            ++i;
        }
    }
    return 0;
}
