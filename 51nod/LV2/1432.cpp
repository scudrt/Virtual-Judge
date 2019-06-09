#include <stdio.h>
#include <algorithm>
int n,m,w[10000];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=n-1;i>=0;--i)
        scanf("%d",&w[i]);
    std::sort(w,w+n);
    int l=0,r=n-1;
    while (r>l)
    {
        if (w[l]+w[r]<=m)
        {
            ++l;
            --n;
        }
        --r;
    }
    printf("%d\n",n);
    return 0;
}
