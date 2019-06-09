#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int map[101][101],f[101][101],ans,n;
void show(int k)
{
    printf("%d\n",f[n][k]);
    int line=n,list[101]={0};
    while (line)
    {
        list[++list[0]]=map[line--][k];
        if (f[line][k]<f[line][k-1])
            --k;
    }
    for (int i=list[0];i>=1;--i)
        printf("%d ",list[i]);
    printf("\n");
}
void deal()
{
    for (int i=1;i<=n;++i)
        for (int j=1;j<=i;++j)
            f[i][j]=map[i][j]+max(f[i-1][j-1],f[i-1][j]);
    int k=1;
    for (int i=1;i<=n;++i)
        if (f[n][i]>f[n][k])
            k=i;
    show(k);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=i;++j)
            scanf("%d",&map[i][j]);
    deal();
    return 0;
}
