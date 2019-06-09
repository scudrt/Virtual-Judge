//simple dp
#include <cstdio>
#define min(a,b) ((a)>(b)?(b):(a))
int f[101][101],s[101],n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int temp;
        scanf("%d",&temp);
        s[i]=s[i-1]+temp;
    }
    for (int l=2;l<=n;++l)
        for (int i=1;i+l-1<=n;++i)
        {
            int j=i+l-1;
            f[i][j]=0x7fffffff;
            for (int k=i;k<=j;++k)
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            f[i][j]+=s[j]-s[i-1];
        }
    printf("%d\n",f[1][n]);
    return 0;
}
