//The true solution is to sort the numbers in greedy way firstlt.
#include <cstdio>
long long ans;
int t,n,a[7],thePow[7];
bool used[7];
int getPow(int num)
{
    if (num<10)
        return 10;
    if (num<100)
        return 100;
    if (num<1000)
        return 1000;
    return 10000;
}
void dfs(int now,long long s)
{
    if (s>ans)
        ans=s;
    for (int i=1;i<=n;++i)
    {
        if (!used[i])
        {
            used[i]=1;
            dfs(now+1,s*thePow[i]+a[i]);
            used[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
        {
            used[i]=0;
            scanf("%d",&a[i]);
            thePow[i]=getPow(a[i]);
        }
        dfs(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}
