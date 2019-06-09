#include <cstdio>
#include <cmath>
int f[10001][14],n,q,a,b;
inline int max(int a,int b)
{
	return a>b?a:b;
}
void preDeal()
{
	for (int k=1;(1<<k)<=n;++k)
		for (int i=1;i+(1<<k)-1<=n;++i)
			f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
}
inline int RMQ()
{
	++a;++b;
	int x=(int)log2(b-a+1);
	return max(f[a][x],f[b-(1<<x)+1][x]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&f[i][0]);
	preDeal();
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",RMQ());
	}
	return 0;
}
