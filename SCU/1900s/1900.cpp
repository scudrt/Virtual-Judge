#include <stdio.h>
int s,n;
int main()
{
    scanf("%d",&n);
    getchar();
    for (int i=1;i<=n;++i)
    {
        s=0;
        for (int k=1;k<=8;++k)
            s=s+s+getchar()-'0';
        printf("%d",s);
        for (int j=2;j<=4;++j)
        {
            s=0;
            for (int k=1;k<=8;++k)
            {
                s=s+s+getchar()-'0';
            }
            printf(".%d",s);
        }
        getchar();
        putchar('\n');
    }
    return 0;
}
