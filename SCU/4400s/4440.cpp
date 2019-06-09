#include <algorithm>
#include <stdio.h>
using namespace std;
int n,m,k,i;
long long ans,temp;
int main()
{
	while (~scanf("%d%d%d",&n,&m,&k))
	{
		ans=0;
		for (i=1;i<=m;++i)
		{
			temp=min(n,max(0,k/2-i));
			temp*=(n+n-temp+1)*(m-i+1);
			ans+=temp/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
