#include <cstdio>
int n,sum,a[50001],b[50001];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        sum=(sum+a[i])%n;
        if (!sum)
        {
            printf("%d\n",i);
            for (int j=1;j<=i;++j)
                printf("%d\n",a[j]);
            break;
        }
        else if (b[sum])
        {
            printf("%d\n",i-b[sum]);
            for (int j=b[sum]+1;j<=i;++j)
                printf("%d\n",a[j]);
            break;
        }
        else
            b[sum]=i;
    }
    return 0;
}
