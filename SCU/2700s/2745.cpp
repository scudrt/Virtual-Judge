#include <cstdio>
#include <cstring>
int a[100001],n,m;
int getLowbit(int x)
{
    return x&(-x);
}
void update(int pos,int x)
{
    while (pos<=n)
    {
        a[pos]+=x;
        pos+=getLowbit(pos);
    }
}
int ask(int pos)
{
    int s=0;
    while (pos)
    {
        s+=a[pos];
        pos-=getLowbit(pos);
    }
    return s;
}
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        while (m--)
        {
            int b,p,q;
            scanf("%d%d%d",&b,&p,&q);
            if (b)
                update(p+1,q);
            else
                printf("%d\n",ask(q+1)-ask(p));
        }
    }
    return 0;
}
