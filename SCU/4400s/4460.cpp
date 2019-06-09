#include <stdio.h>
#include <algorithm>
int a[100001],b[100001],t,n,m,ans;
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for (int i=1;i<=m;++i)
            scanf("%d",&b[i]);
        std::sort(a+1,a+n+1);
        std::sort(b+1,b+m+1);
        int pa=n,pb=m;
        while (pa && pb)
        {
            while (a[pa]>b[pb])
                --pa;
            if (pa && pb)
                ++ans;
            else
                break;
            --pa;
            --pb;
        }
        printf("%d\n",ans);
    }
    return 0;
}
