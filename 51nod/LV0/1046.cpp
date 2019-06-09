#include <iostream>
using namespace std;
int a,b,c;
int deal()
{
//just fastpow
	long long temp=a,s=1;
	while (b)
	{
		if (b&1)
		{
			s*=temp;
			s%=c;
		}
		b/=2;
		temp=(temp*temp)%c;
	}
	return s;
}
int main()
{
	cin >> a >> b >> c;
	cout << deal() << endl;
	return 0;
}
