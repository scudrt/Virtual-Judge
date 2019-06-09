#include <cstdio>
#include <algorithm>
int n,m,a[100001];
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        for (int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        std::sort(a+1,a+n+1);
        int s=0;
        for (int k=n;k>=1;--k)
        {
            s+=a[k];
            if (s>=m)
            {
                printf("%d\n",n-k+1);
                break;
            }
        }
        if (s<m)
            printf("-1\n");
    }
    return 0;
}
