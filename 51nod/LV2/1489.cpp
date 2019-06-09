#include <stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define maxn 13
int a,b,c[maxn],n,ans=0x7fffffff;
void dfs(int now,int step)
{
    if (now==n)
    {
        if (c[now]<0)
            ans=min(ans,step);
        return;
    }
    if (step>ans)
        return;
    if (c[now-1]<0 && now<n-1)
        dfs(now+1,step);
    for (int i=0;i<16;++i)
    {
        if (c[now-1]>=i*b)
            continue;
        c[now-1]-=b*i; c[now+1]-=b*i; c[now]-=a*i;
        dfs(now+1,step+i);
        c[now-1]+=b*i; c[now+1]+=b*i; c[now]+=a*i;
        if (c[now-1]<i*b && c[now]<i*a && now!=n-1)
            break;
    }
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for (int i=1;i<=n;++i)
        scanf("%d",&c[i]);
    dfs(2,0);
    printf("%d\n",ans);
    return 0;
}
