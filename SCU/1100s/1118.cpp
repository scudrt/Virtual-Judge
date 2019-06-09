#include <cstdio>
int n,a,x,m,k;
int fa,fk;
struct num
{
    int a,x;
    num(int,int);
    num operator +(const num&)const;
    num operator -(const num&)const;
}target(0,0);
num::num(int a,int x)
{
    this->a=a;
    this->x=x;
}
num num::operator +(const num& temp)const
{
    return num(temp.a+this->a,temp.x+this->x);
}
num num::operator -(const num& temp)const
{
    return num(-temp.a-this->a,-temp.x-this->x);
}
void deal(int now,num up,num lup,num rest)
{
    if (now==x)
    {
        target=rest;
    }
    if (now==n-1)
    {
        k=(m-rest.a*a)/rest.x;
        return;
    }
    deal(now+1,up+lup,up,rest+lup);
}
int main()
{
    scanf("%d%d%d%d",&a,&n,&m,&x);
    deal(2,num(0,1),num(1,0),num(1,0));
    printf("%d\n",target.a*a+target.x*k);
    return 0;
}
