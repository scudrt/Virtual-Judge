#include <cstdio>
#include <algorithm>
#define min(a,b) ((a)>(b)?(b):(a))
#define MAX_INT 0x7fffffff
int n,m,ans,a[41];
void dfs(int now,int sum)
{
    if (ans==m)
        return;
    while (now<=n)
    {
        if (ans==m)
            return;
        if (a[now]+sum>=m)
        {
            ans=min(ans,a[now]+sum);
            return;
        }
        dfs(now+1,a[now]+sum);
        ++now;
    }
}
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        long long s=0;
        ans=MAX_INT;
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        if (s<m)
        {
            printf("-1\n");
            continue;
        }
        std::sort(a+1,a+n+1);
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
