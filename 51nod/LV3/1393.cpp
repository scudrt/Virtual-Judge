#include <stdio.h>
#define MAXN 1000000
#define max(a,b) (a>b?a:b)
int hash[2000001],sum,now,ans;
int main()
{
    int ch;
    while (~(ch=getchar()) && ch!='\n')
    {
        ++now;
        sum+=(ch-'0')*2-1;
        if (!sum)
            hash[MAXN]=now;
        else if (!hash[sum+MAXN])
            hash[sum+MAXN]=now;
        else
            ans=max(ans,now-hash[sum+MAXN]);
    }
    printf("%d\n",max(ans,hash[MAXN]));
    return 0;
}
