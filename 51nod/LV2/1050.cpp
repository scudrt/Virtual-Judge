//1.max sum from 1-n is max1
//2.max sum from n-1 is max2
//3.min sum from 1-n is min1
//max1 and min1 are easy to calculate
//max2 equals to the total sum minus min1 (key point)
#include <cstdio>
#define MAXN 50001
int n;
long long maxs[MAXN],mins[MAXN],s;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lld",&maxs[i]);
		mins[i]=maxs[i];
		s+=maxs[i];
    
		if (maxs[i-1]>0)
			maxs[i]+=maxs[i-1];
		if (mins[i-1]<0)
			mins[i]+=mins[i-1];
		if (maxs[0]<maxs[i])
			maxs[0]=maxs[i];
		if (mins[0]>mins[i])
			mins[0]=mins[i];
	}
	printf("%lld\n",maxs[0]>(s-mins[0])?maxs[0]:(s-mins[0]));
	return 0;
}
