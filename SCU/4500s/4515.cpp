#include <stdio.h>
int n,m,k,rest,t,a[101];
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        bool f[100001]={1};
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&m);
            int used[100001]={0};
            for (int now=0;now<=k-a[i];++now)
                if (f[now] && m>=used[now]+1)
                {
                    ++used[now];
                    f[now+a[i]]=1;
                }
        }
        printf("%s\n",f[k]?"yes":"no");
    }
    return 0;
}
