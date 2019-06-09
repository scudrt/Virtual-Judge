//greedy
#include <iostream>
#include <algorithm>
using namespace std;
int n,ans;
struct node
{
	int a,b;
	bool operator <(const node&)const;
}t[1001];
bool node::operator<(const node& x)const
{ //may be there is a problem
	return b<x.b;
}
void deal()
{
	sort(t+1,t+n+1);
	int last=0;
	for (int i=1;i<=n;++i)
	{
		if (t[i].a>=t[last].b)
		{
			last=i;
			++ans;
		}
	}
}
int main()
{
	while (cin >> n)
	{
		if (n==0)
			break;
		ans=0;
		for (int i=1;i<=n;++i)
			cin >> t[i].a >> t[i].b;
		deal();
		cout << ans << endl;
	}
	return 0;
}
