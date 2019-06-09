#include <cstdio>
int t,n,k,s[200001],ss;
int deal()
{
    int temp=n+n;
    for (int i=k+1;i<temp;++i)
    {
        ss+=s[i];
        if (ss<0)
        {
            ss=0;
            k=i;
        }
        else if (i-k==n)
            return k;
    }
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        ss=k=0;
        int sum=0,a,b;
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
        {
            scanf("%d%d",&a,&b);
            s[n+i]=s[i]=a-b;
            sum+=s[i];
            ss+=s[i];
            if (ss<0)
            {
                ss=0;
                k=i;
            }
        }
        if (sum<0)
            printf("-1\n");
        else if (!k)
            printf("0\n");
        else
            printf("%d\n",deal());
    }
    return 0;
}
