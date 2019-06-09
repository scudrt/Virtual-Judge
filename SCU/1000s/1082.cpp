#include <iostream>
using namespace std;
int n,a[11],ans;
void dfs(int now)
{
	if (now==n+1)
	{
		++ans;
		return;
	}
	if (a[now])
	{
		int temp=a[now]-a[now-1];
		if (now==1 || (temp>=-1 && temp<=1))
		{
			dfs(now+1);
		}
		return;
	}
	for (int i=1;i<=n;++i)
  //choose the position to place from 1 to n
	{
		int temp=i-a[now-1];
		if (now==1 || (temp>=-1 && temp<=1))
		{
			a[now]=i;
			dfs(now+1);
			a[now]=0;
		}
	}
}
int main()
{
	while (cin >> n)
	{
		if (n==0)
		{
			break;
		}
		ans=0;
		for (int i=1;i<=n;++i)
		{
			cin >> a[i];
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
