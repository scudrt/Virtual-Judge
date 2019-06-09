#include <cstdio>
int n,a,f[1000001];
int main()
{
    while (~scanf("%d",&n))
    {
        f[0]=0;
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&a);
            if (a>f[f[0]])
                f[++f[0]]=a;
            else
            {
                int l=1,r=f[0],mid;
                while (l<r)
                {
                    mid=(l+r)>>1;
                    if (f[mid]<a)
                        l=mid+1;
                    else
                        r=mid;
                }
                f[l]=a;
            }
        }
        printf("%d\n",f[0]);
    }
    return 0;
}
