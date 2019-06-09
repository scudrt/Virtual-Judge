//emirp
#include <stdio.h>
int prime[17]={16,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53},k;
long long n,s;
void dfs(long long nows,int nowk,int now,int last)
{
    if (nowk>k)
    {
        k=nowk;
        s=nows;
    }
    else if (nowk==k && s>nows)
        s=nows;
    if (now>prime[0])
        return;
    int tempk=nowk;
    for (int i=1;i<=last;++i)
    {
        if (nows<=n/prime[now])
            dfs(nows*=prime[now],nowk+=tempk,now+1,i);
        else
            break;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        s=k=1;
        scanf("%lld",&n);
        dfs(1,1,1,60);
        printf("%lld %d\n",s,k);
    }
    return 0;
}
