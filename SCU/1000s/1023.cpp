//predeal the prime numbers and be care about the output fromat
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 1000
bool isPrime[MAXN+1];
int list[MAXN+1],n,c;
void preDeal()
{
	isPrime[1]=isPrime[2]=1;
	for (int i=3;i<=MAXN;++i)
	{
		isPrime[i]=1;
	}
	int temp=(int)sqrt(MAXN);
	for (int i=3;i<=temp;++i)
	{
		if (isPrime[i])
			for (int j=i+i;j<=MAXN;j+=i)
				isPrime[j]=0;
	}
	list[1]=1;
	list[2]=2;
	list[0]=2;
	for (int i=3;i<=MAXN;i+=2)
	{
		if (isPrime[i])
			list[++list[0]]=i;
	}
}
int main()
{
	preDeal();
	while (cin >> n >> c)
	{
		cout << n << ' ' << c << ':';
		int l=1,r=list[0],mid;
		while (l<r)
		{
			mid=(l+r)/2;
			if (list[mid]<n)
				l=mid+1;
			else
				r=mid;
		}
		while (list[l]>n)
			--l;
		int a=l/2-c+2,b=l/2+c;
		if (!(l&1))
			--a;
		if (c+c>=l)
		{
			a=1;
			b=l;
		}
		for (int i=a;i<=b;++i)
			cout << ' ' << list[i];
		cout << "\n\n";
	}
	return 0;
}
