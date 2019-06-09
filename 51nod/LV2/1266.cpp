//greedy
#include <cstdio>
#include <cmath>
using namespace std;
int a,n,l,ans1,ans2;
int min(int a,int b)
{
	if (b<a)
		return b;
	return a;
}
int max(int a,int b)
{
	if (a>b)
		return a;
	return b;
}
int main()
{
	scanf("%d%d",&n,&l);
	int mid=l/2;
	if (l&1)
		++mid;
	while (n--)
	{
		scanf("%d",&a);
		ans1=max(ans1,min(l-a,a));
		ans2=max(ans2,max(l-a,a));
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
