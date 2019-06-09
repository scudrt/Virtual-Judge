#include <iostream>
#include <algorithm>
using namespace std;
int n,a[50001],s,temp[50001];
void mysort(int left,int right)
{//merge sort
	if (left>=right)
	{
		return;
	}
	int mid=(left+right)/2;
	mysort(left,mid);
	mysort(mid+1,right);
	int pl=left,pr=mid+1,pk=left-1;
	while (pl<=mid && pr<=right)
	{
		if (a[pl]<=a[pr])
		{
			temp[++pk]=a[pl++];
		}
		else
		{
			temp[++pk]=a[pr++];
			s+=mid-pl+1;
		}
	}
	if (pl<=mid)
	{
		while (pl<=mid)
		{
			temp[++pk]=a[pl++];
		}
	}
	if (pr<=right)
	{
		while (pr<=right)
		{
			temp[++pk]=a[pr++];
		}
	}
	for (int i=left;i<=right;++i)
	{
		a[i]=temp[i];
	}
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		cin >> a[i];
	}
	mysort(1,n);
	cout << s << endl;
	return 0;
}
