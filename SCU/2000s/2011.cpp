#include <cstdio>
int main()
{
    int ans,n;
    while (~scanf("%d",&n))
    {
        ans=1;
        int temp=1%n;
        while (temp)
        {
            ++ans;
            temp=(temp*10+1)%n; //key
        }
        printf("%d\n",ans);
    }
    return 0;
}
