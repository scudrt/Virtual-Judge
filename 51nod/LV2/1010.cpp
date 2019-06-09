//ugly number problem
#include <cstdio>
#include <iostream>
#include <algorithm>
unsigned long long MAXN=1000000000;
int n;
unsigned long long a,line[10958],f[64][42][30];
void preDeal()
{
	MAXN*=MAXN;
	f[0][0][0]=1;
	for (int i=0;i<=62;++i)
	{
		for (int j=0;j<=40;++j)
		{
			for (int k=0;k<=28;++k)
			{
				unsigned long long t=f[i][j][k];
				if (t>MAXN || t==0)
					break;
				f[i+1][j][k]=t*2;
				f[i][j+1][k]=t*3;
				f[i][j][k+1]=t*5;
				line[++line[0]]=f[i][j][k];
			}
		}
	}
	std::sort(line+1,line+1+line[0]);
}
long long deal()
{
	int l=2,r=line[0],mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (line[mid]>=a)
			r=mid;
		else
			l=mid+1;
	}
	return line[l];
}
int main()
{
	preDeal();
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lld",&a);
		std::cout << deal() << '\n';
	}
	return 0;
}
