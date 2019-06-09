//using log2 to reduce the calculated amount.
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int n,m,a,b,ans;
double line[10001];
void solve()
{
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			line[int(++line[0])]=log2(a+i)*(b+j);
		}
	}
	sort(line+1,line+(int)line[0]+1);
	double now=0;
	for (int i=1;i<=line[0];++i)
	{
		if (line[i]==now)
			continue;
		else
		{
			++ans;
			now=line[i];
		}
	}
}
int main()
{
	cin >> m >> n >> a >> b;
	solve();
	cout << ans << endl;
	return 0;
}
