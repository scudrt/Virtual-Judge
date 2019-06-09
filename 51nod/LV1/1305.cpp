
//Try to calculate some couples,you will find the rule.

#include <iostream>
using namespace std;
int n,two,one[100001],a[100001];
long long fun()
{
	long long temp=0;
	temp+=two*(two-1)/2;
	for (int i=1;i<=n;++i)
	{
		if (a[i]==1)
		{
			temp+=one[n]-one[i]+n-i;
		}
		else
		{
			temp+=one[n]-one[i];
		}
	}
	return temp;
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		cin >> a[i];
		one[i]=one[i-1];
		if (a[i]==1)
			++one[i];
		else if (a[i]==2)
			++two;
	}
	cout << fun() << endl;
	return 0;
}
