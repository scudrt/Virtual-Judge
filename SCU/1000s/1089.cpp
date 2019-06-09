#include <iostream>
using namespace std;
int n,ans,rest,a[101];
void dfs(int now,int from)
{
	if (now==4)
	{
		if (rest==0)
			++ans;
		return;
	}
	for (int i=from;i<=n;++i)
		if (a[i]<=rest)
		{
			rest-=a[i];
			dfs(now+1,i+1);
			rest+=a[i];
		}
}
int main()
{
	while (cin >> n >> rest)
	{
		if (n==0 && rest==0)
			break;
		ans=0;
		for (int i=1;i<=n;++i)
			cin >> a[i];
		dfs(1,1);
		cout << ans << endl;
	}
	return 0;
}
