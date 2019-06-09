#include <stdio.h>
int list[8001],num,n,i,j;
int main()
{
    scanf("%d",&n);
    n=(n>>3);
    for (i=1;i<=n;++i)
    {
        scanf("%d",&num);
        for (j=i*8;j>(i-1)*8;--j)
        {
            list[j]=num&1;
            num=(num>>1);
        }
    }
    n=(n<<3);
    for (i=1;i<=n;++i)
    {
        int num=(list[i]<<7);
        j=i;
        while (list[j]==list[i] && j<=n)
            ++j;
        num+=j-i;
        i=j-1;
        printf("%d ",num);
    }
    printf("\n");
    return 0;
}
