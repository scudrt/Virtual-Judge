#include <math.h>
#include <stdio.h>
#include <algorithm>
#define MAX 0x7fffffff
int n,ans,a[20001];
bool cmp(int a,int b)
{
    if (abs(a)!=abs(b))
        return abs(a)<abs(b);
    return a<b;
}
int main()
{
    int s=0;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",&a[i],&a[i+n]);
        a[i+n]=-a[i+n];
    }
    n+=n;
    std::sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i)
    {
        if (a[i]<0)
            --s;
        else
            ++s;
        if (s>ans)
            ans=s;
    }
    printf("%d\n",ans);
    return 0;
}
