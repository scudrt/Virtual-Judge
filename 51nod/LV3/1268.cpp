#include <cstdio>
int n,k,a[21];
bool flag;
void dfs(int now)
{
	if (now>n)
	{
		if (k==0)
			flag=true;
		return;
	}
	if (flag)
		return;
	k-=a[now];
	dfs(now+1);
	k+=a[now];
	dfs(now+1);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	dfs(1);
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
