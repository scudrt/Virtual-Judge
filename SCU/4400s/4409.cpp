//greedy, 7 first
#include <cstdio>
int t,n,ans,s[2];
void deal()
{
    s[0]=s[1]=0;
    ans=0;
    s[1]=n/7;
    if (n%7==0)
        ans=1;
    else
    {
        n%=7;
        s[0]=n/4;
        n%=4;
        if (s[1]>=n)
        {
            ans=1;
            s[1]-=n;
            s[0]+=n+n;
        }
    }
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        deal();
        if (ans==0)
            printf("-1");
        else
        {
            while (s[0]--)
                printf("4");
            while (s[1]--)
                printf("7");
        }
        printf("\n");
    }
    return 0;
}
