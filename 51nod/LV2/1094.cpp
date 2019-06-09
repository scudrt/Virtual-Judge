#include <iostream>
#include <algorithm>
using namespace std;
int n,k,ans1,ans2;
struct node
{
	int s,pos;
	bool operator<(const node&)const;
}t[10001];
bool node::operator<(const node& x)const
{
	return s<x.s;
}
bool deal()
{
	int l,r,mid,target;
	ans1=ans2=0x7fffffff;
	for (int i=0;i<=n;++i)
	{
		l=0;r=n;
		target=k+t[i].s;
		while (l<r)
		{
			mid=(l+r)/2;
			if (t[mid].s>=target)
				r=mid;
			else
				l=mid+1;
		}
		if (t[r].s != target || t[r].pos<t[i].pos+1)
			continue;
		if (t[i].pos+1<ans1)
		{
			ans1=t[i].pos+1;
			ans2=t[l].pos;
		}
		else if (t[i].pos+1==ans1 && t[l].pos<ans2)
			ans2=t[l].pos;
	}
	if (ans1==ans2 && ans1==0x7fffffff)
		return false;
	return true;
}
int main()
{
	cin >> n >> k;
	for (int i=1;i<=n;++i)
	{
		cin >> t[i].s;
		t[i].s+=t[i-1].s;
		t[i].pos=i;
	}
	sort(t,t+n+1);
	if (deal())
		cout << ans1 << ' ' << ans2 << endl;
	else
		cout << "No Solution" << endl;
	return 0;
}
