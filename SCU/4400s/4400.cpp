#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define maxn 501
int n,m,t,ans,map[maxn][maxn],d[maxn];
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        ans=-0x7fffffff;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
            {
                scanf("%d",&map[i][j]);
                map[i][j]+=map[i-1][j];
            }
        for (int i=1;i<=n;++i)
            for (int j=i;j<=n;++j)
                for (int k=1;k<=m;++k)
                {
                    d[k]=map[j][k]-map[i-1][k];
                    if (d[k-1]>0)
                        d[k]+=d[k-1];
                    ans=max(d[k],ans);
                }
        printf("%d\n",ans);
    }
    return 0;
}
