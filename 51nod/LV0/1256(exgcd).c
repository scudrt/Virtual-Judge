//using exgcd
#include <stdio.h>
int exgcd(int a,int b,int *x,int *y)
{
	int d=a;
	if (!b)
	{
		(*x)=1;
		(*y)=0;
	}
	else
	{
		d=exgcd(b,a%b,y,x);
		(*y)-=(a/b)*(*x);
	}
	return d;
}
int deal(int a,int n)
{
	int x,y;
	exgcd(a,n,&x,&y);
	return (x+n)%n;
}
int main()
{
	int a,n;
	while (~scanf("%d%d",&a,&n))
	{
		if (!a)
			break;
		printf("%d\n",deal(a,n));
	}
	return 0;
}
