#include <iostream>
#include <cstring>
using namespace std;
int map[101][101],match[101],ans,n,m;
bool used[101];
bool dfs(int now)
{
	int from=1,to=n;
	if (now<=m)
		from=m+1;
	else
		to=m;
	for (int i=from;i<=to;++i)
		if (!used[i] && map[i][now])
		{
			used[i]=1;
			if (!match[i] || dfs(match[i]))
			{
				match[i]=now;
				match[now]=i;
				return true;
			}
		}
	return false;
}
int main()
{
	cin >> m >> n;
	int a,b;
	while (cin >> a >> b)
	{
		if (a==b && a==-1)
			break;
		map[a][b]=map[b][a]=1;
	}
	for (int i=1;i<=n;++i)
		if (!match[i])
		{
			memset(used,0,sizeof(used));
			if (dfs(i))
				++ans;
		}
	if (!ans)
		cout << "No Solution!\n";
	else
		cout << ans << endl;
	return 0;
}
