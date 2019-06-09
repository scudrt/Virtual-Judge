//LIS problem. O(nlogn)
#include <iostream>
using namespace std;
int n,a[50001],f[50001];
void deal()
{
	f[++f[0]]=a[1];
	for (int i=2;i<=n;++i)
	{
		if (f[f[0]]<a[i])
		{
			f[++f[0]]=a[i];
		}
		else
		{
			int l=1,r=f[0],mid;
			while (l<r)
			{
				mid=(l+r)/2;
				if (f[mid]<a[i])
				{
					l=mid+1;
				}
				else
				{
					r=mid;
				}
			}
			f[l]=a[i];
		}
	}
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		cin >> a[i];
	}
	deal();
	cout << f[0] << endl;
	return 0;
}
