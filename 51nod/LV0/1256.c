//ans=num^(eular(mod)-1)%mod
//can also use exgcd
#include <stdio.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
int num,mod,x;
int eular(int n)
{
	int s=n,i,temp=(int)sqrt(n);
	if (!(n&1))
		s=n/2;
	while (!(n&1))
		n=n>>1;
	for (i=3;i<=temp;i+=2)
	{
		if (n%i==0)
		{
			s=s/i*(i-1);
			while (n%i==0)
				n/=i;
		}
	}
	if (n>1)
		s=s/n*(n-1);
	return s;
}
int deal()
{
	int now=1,s=1,k=eular(mod)-1;
	long long times=num;
	while (now<=k)
	{
		if (now&k)
			s=s*times%mod;
		now+=now;
		times=times*times%mod;
	}
	return s;
}
int main()
{
	while (~scanf("%d%d",&num,&mod))
	{
		if (!num)
			break;
		printf("%d\n",deal());
	}
	return 0;
}
