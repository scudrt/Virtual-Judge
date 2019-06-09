#include <stdio.h>
#include <algorithm>
#define maxn 200001
int n,ans,a[maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    std::sort(a+1,a+n+1);
    for (int i=1;i<n;++i)
    {
        int s=a[i];
        while (1)
        {
            s+=a[i];
            int l=i+1,r=n,mid;
            while (l<r)
            {
                mid=(l+r)>>1;
                if (a[mid]<s)
                    l=mid+1;
                else
                    r=mid;
            }
            if (a[l]>=s)
                ans=std::max(ans,a[l-1]%a[i]);
            else
                ans=std::max(ans,a[l]%a[i]);
            if (s>=a[n])
                break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
