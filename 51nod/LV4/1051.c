#include <stdio.h>
long long map[501][501],ans=-(0x7fffffff);
int n,m;
int main()
{
    register int i,j;
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            scanf("%lld",&map[i][j]);
            map[i][j]+=map[i-1][j];
        }
    for (i=1;i<=n;++i)
    {
        for (j=i;j<=n;++j)
        {
            long long s=0;
            for (int k=1;k<=m;++k)
            {
                if (s<0)
                    s=map[j][k]-map[i-1][k];
                else
                    s+=map[j][k]-map[i-1][k];
                if (s>ans)
                    ans=s;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
