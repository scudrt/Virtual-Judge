#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 10000000
bool p[MAXN+1];
int prime[670001],n;
void preDeal()
{
	int temp=(int)sqrt(MAXN);
	
	p[2]=1;
	prime[++prime[0]]=2;

	for (int i=3;i<=MAXN;i+=2)
		p[i]=1;

	for (int i=3;i<=temp;i+=2)
	{
		if (p[i])
		{
			prime[++prime[0]]=i;
			for (int j=i+i;j<=MAXN;j+=i)
			{
				p[j]=0;
			}
		}
	}
	for (int i=prime[prime[0]]+2;i<=MAXN;i+=2)
	{
		if (p[i])
		{
			prime[++prime[0]]=i;
		}
	}
}
int deal()
{
	preDeal();
	int l=1,r=prime[0],mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (prime[mid]<n)
			l=mid+1;
		else
			r=mid;
	}
	//l==r
	mid=l;
	while (1)
	{
		if (p[mid])
		{
			return prime[mid];
		}
		++mid;
	}
	return 0;
}
int main()
{
	cin >> n;
	cout << deal() << endl;
	return 0;
}
