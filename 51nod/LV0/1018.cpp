//cleaner and faster merge sort
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[50001],temp[50001];
void mysort(int left,int right)
{
	if (left>=right)
	{
		return;
	}
	if (left==right-1 && a[left]<=a[right])
	{
		return;
	}
	int mid=(left+right)/2;
	int pl=left,pr=mid+1,pk=left-1;
	mysort(left,mid);
	mysort(mid+1,right);
	while (pl<=mid || pr<=right)
	{
		if (pr>right)
		{
			temp[++pk]=a[pl++];
		}
		else if (pl>mid)
		{
			temp[++pk]=a[pr++];
		}
		else if (a[pl]<=a[pr])
		{
			temp[++pk]=a[pl++];
		}
		else if (a[pl]>a[pr])
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
	for (int i=1;i<=n;++i)
	{
		cout << a[i] << endl;
	}
	return 0;
}
