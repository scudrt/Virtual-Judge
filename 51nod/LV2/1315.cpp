#include <cstdio>
int ans,n,x;
int tick[33];
bool cover(int now)
{
    int temp=x;
    while (now)
    {
        if (now&1 && !(temp&1))
            return false;
        now=now>>1;
        temp=temp>>1;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&x);
    ans=n;
    for (int i=1;i<=n;++i)
    {
        int temp,now=1;
        scanf("%d",&temp);
        if (cover(temp))
        {
            while (temp)
            {
                tick[now]+=(temp&1);
                ++now;
                temp=temp>>1;
            }
        }
    }
    for (int i=1;i<=32;++i)
    {
        if (x&1)
            if (ans>tick[i])
                ans=tick[i];
        x=x>>1;
    }
    printf("%d\n",ans);
    return 0;
}
