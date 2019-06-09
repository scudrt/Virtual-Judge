#include <cstdio>
#include <algorithm>
int t,tick;
char a[5];
void deal()
{
    int sum1=0,sum2=0;
    std::sort(a,a+4);
    for (int i=0;i<=3;++i)
    {
        sum1=sum1*10+a[3-i]-'0';
        sum2=sum2*10+a[i]-'0';
    }
    sum1-=sum2;
    for (int i=3;i>=0;--i)
    {
        a[i]=sum1%10+'0';
        sum1/=10;
    }
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%s%d",a,&tick);
        if (tick>=7)
        {
            printf("6174\n");
            continue;
        }
        while (tick--)
            deal();
        int i=0;
        while (a[i]=='0' && i!=3)
            ++i;
        for (;i<=3;++i)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
