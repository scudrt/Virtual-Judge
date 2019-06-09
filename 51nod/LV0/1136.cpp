#include <cstdio>
#include <cmath>
int main()
{
    int n,s,temp;
    scanf("%d",&n);
    s=n;
    if (!(n&1))
    {
        s=(s>>1);
        while (!(n&1))
            n=(n>>1);
    }
    temp=(int)sqrt(n);
    for (int i=3;i<=temp;i+=2)
        if (n%i==0)
        {
            s=s/i*(i-1);
            while (n%i==0)
                n/=i;
        }
    if (n>1)
        s=s/n*(n-1);
    printf("%d\n",s);
    return 0;
}
