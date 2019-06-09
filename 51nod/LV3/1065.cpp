//hard to think that I should sort them including the 0th.
#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long ans=0x7fffffff;
struct node
{
	int pos;
	long long sum;
	bool operator <(const node& x)const;
}t[50001];
bool node::operator < (const node& x)const
{
	return sum<x.sum;
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		cin >> t[i].sum;
		t[i].sum+=t[i-1].sum;
		t[i].pos=i;
	}
	sort(t,t+n+1);
	for (int i=1;i<=n;++i)
	{
		int temp=t[i].sum-t[i-1].sum;
		if (t[i].pos>t[i-1].pos && temp>0)
		{
			if (ans>temp)
				ans=temp;
		}
	}
	cout << ans << endl;
	return 0;
}
