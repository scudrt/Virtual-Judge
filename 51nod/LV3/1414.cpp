#include <stdio.h>
#define maxn 20001
int ans,n,a[maxn];
bool used[maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	for (int i=2;i<=n/3;++i)
		if (n%i==0)
			for (int k=1;k<=i;++k)
			{
				int sum=0;
				for (int j=k;j<=n;j+=i)
					sum+=a[j];
				if (sum>ans)
					ans=sum;
			}
	printf("%d\n",ans);
	return 0;
}
