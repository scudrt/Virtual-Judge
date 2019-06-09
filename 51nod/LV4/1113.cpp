#include <stdio.h>
#define mod 1000000007
long long map[101][101],temp[101][101];
int n,k;
void mul(long long a[101][101],long long b[101][101])
{
    long long temp[101][101]={0};
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k)
                temp[j][i]=(temp[j][i]+a[j][k]*b[k][i])%mod;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            a[i][j]=temp[i][j];
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            scanf("%lld",&map[i][j]);
            temp[i][j]=map[i][j];
        }
    --k;
    while (k)
    {
        if (k&1)
            mul(map,temp);
        k=k>>1;
        mul(temp,temp);
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            printf("%lld ",map[i][j]);
        printf("\n");
    }
    return 0;
}
