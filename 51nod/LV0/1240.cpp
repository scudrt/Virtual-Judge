#include <cstdio>
int n,ans,prime[4001]={1,2};
void preDeal()
{
	bool isPrime[35001]={0};
	for (int i=3;i<=35000;i+=2)
		isPrime[i]=1;
	for (int i=3;i<=200;i+=2)
		if (isPrime[i])
			for (int j=i+i;j<=35000;j+=i)
				isPrime[j]=0;
	for (int i=3;i<=35000;i+=2)
		if (isPrime[i])
			prime[++prime[0]]=i;
}
void deal()
{
	int top=1;
	while (top<=prime[0] && prime[top]<=n)
	{
		if (n%prime[top]==0)
		{
			n/=prime[top];
			++ans;
			if (n%prime[top]==0)
			{
				ans=0;
				return;
			}
		}
		++top;
	}
	if (n>1)
		++ans;
	ans=1-2*(ans&1);
}
int main()
{
	preDeal();
	scanf("%d",&n);
	deal();
	printf("%d\n",ans);
	return 0;
}
