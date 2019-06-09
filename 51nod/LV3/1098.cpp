#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
double a[10001];
long long ans=100000000;
void deal()
{
	ans*=ans;
	sort(a+1,a+n+1);
	for (int i=1;i<=n;++i)
		a[i]+=a[i-1];
	double avg,temp;
	for (int i=1;i<=n-m+1;++i)
	{
		temp=0;
		avg=(a[i+m-1]-a[i-1])/m;
		for (int j=i;j<=i+m-1;++j)
		{
			double d=a[j]-a[j-1]-avg;
			temp+=d*d;
		}
		if (temp<ans)
			ans=(long long)temp;
	}
}
int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;++i)
		cin >> a[i];
	deal();
	cout << ans << endl;
	return 0;
}
