//it is a little hard to think about the greedy policy
#include <iostream>
using namespace std;
int a[50001],b[50001],n,ans;
int max(int a,int b)
{
	if (a>=b)
		return a;
	return b;
}
void sort(int left,int right)
{
	if (left>=right)
		return;
	int l=left,r=right,ka=a[left],kb=b[left];
	while (l<r)
	{
		while (l<r && a[r]>=ka)
			--r;
		a[l]=a[r];
		b[l]=b[r];
		while (l<r && a[l]<=ka)
			++l;
		a[r]=a[l];
		b[r]=b[l];
	}
	a[l]=ka;
	b[l]=kb;
	sort(left,l-1);
	sort(l+1,right);
}
void deal()
{
	int far=b[1],temp;
	for (int i=2;i<=n;++i)
	{
		if (far<b[i])
		{
			temp=far-a[i];
			far=b[i];
		}
		else
		{
			temp=b[i]-a[i];
		}
		ans=max(ans,temp);
	}
}
int main()
{
	cin >> n;
	int temp=n;
	while (temp--)
		cin >> a[temp+1] >> b[temp+1];
	sort(1,n);
	deal();
	cout << ans << endl;
	return 0;
}
