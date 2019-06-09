/*
*quite a hard one
*spent about 3 hours on it
*I can't explain how to do it now.
*anyway there is a optimization to reduce the recursion for function 'g'
*/
#include <cstdio>
#include <cmath>
const int maxn=10000000;
int n,c[maxn+1];
long long f[maxn+1];
void preDeal()
{
	c[2]=1;
	int temp=(int)sqrt(maxn);
	for (int i=3;i<=maxn;i+=8)
		c[i]=c[i+2]=c[i+4]=c[i+6]=1;
	for (int i=3;i<=temp;i+=2)
		if (c[i])
			for (int j=i+i;j<=maxn;j+=i)
				c[j]=0;
	f[1]=0;
	for (int i=2;i<=maxn;i+=4)
	{
		f[i]=f[i-1];
		if (c[i])
			++f[i];
		f[i+1]=f[i];
		if (c[i+1])
			++f[i+1];
		f[i+2]=f[i+1];
		if (c[i+2])
			++f[i+2];
		f[i+3]=f[i+2];
		if (c[i+3])
			++f[i+3];
	}
	c[0]=1;
	c[1]=2;
	for (int i=3;i<=maxn;i+=6)
	{
		if (c[i])
			c[++c[0]]=i;
		if (c[i+2])
			c[++c[0]]=i+2;
		if (c[i+4])
			c[++c[0]]=i+4;
	}
}
long long g(long long a,int b)
{
	if (b<=1)
		return a-a/2*b;
	if (b==2)
		return a-a/2-a/3+a/6;
	if (b==3)
		return a-a/2-a/3-a/5+a/6+a/10+a/15-a/30;
	if (a<=maxn)
	{
		if (f[a]<=b)
			return 1;
		if (f[(int)sqrt(a)]<=b)
			return f[a]+1-b;
	}
	return g(a,b-1)-g(a/c[b],b-1);
}
long long sum(long long x)
{
	if (x<=maxn)
		return f[x];
	int temp=(int)sqrt(x);
	return f[temp]+g(x,f[temp])-1;
}
int main()
{
	preDeal();
	while (scanf("%d",&n)==1)
	{
		if (n<=c[0])
		{
			printf("%d\n",c[n]);
			continue;
		}
		long long l=2,r=(long long)(n*log(n)+n*log(log(n))),m;
		while (l<r)
		{
			m=(l+r)/2;
			long long temp=sum(m);
			if (temp>n)
				r=m-1;
			else if (temp<n)
				l=m+1;
			else
				r=m;
		}
		printf("%lld\n",l);
	}
	return 0;
}
