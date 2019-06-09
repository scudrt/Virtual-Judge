#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define maxn 1001
#define maxm 2001
int head[maxn],go[maxm],v[maxm],w[maxm];
int a,b,c,n,q,dp[maxn][maxn],dis[maxn];
inline void add(int a,int b,int c,int num)
{
    v[num]=b;
    w[num]=c;
    go[num]=head[a];
    head[a]=num;
}
int dij(int from,int to)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > t;
    memset(dis,127,sizeof(dis));
    dis[from]=0;
    t.push(make_pair(0,from));
    while (!t.empty())
    {
        pair<int,int> temp=t.top();
        int now=temp.second;
        t.pop();
        if (dis[now]<temp.first)
            continue;
        for (int i=head[now];i;i=go[i])
        {
            if (dis[v[i]]>dis[now]+w[i])
            {
                dis[v[i]]=dis[now]+w[i];
                t.push(make_pair(dis[v[i]],v[i]));
            }
        }
    }
    for (int i=1;i<=n;++i)
        dp[i][from]=dp[from][i]=dis[i];
    return dis[to];
}
int main()
{
    while (~scanf("%d%d",&n,&q))
    {
        memset(head,0,sizeof(head));
        memset(dp,0,sizeof(dp));
        for (int i=1;i<n;++i)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c,i);
            add(b,a,c,i+n);
        }
        while (q--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",dp[a][b]?dp[a][b]:dij(a,b));
        }
    }
    return 0;
}
