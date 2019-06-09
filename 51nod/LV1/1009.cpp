#include <iostream>
using namespace std;
int x,ans;
int main()
{
	cin >> x;
	int mul=1;
	while (mul<=x)
	{
		int a=x/(mul*10),b=x/mul%10;
		if (b==0)
		{
			ans+=a*mul;
		}
		else
		{
			ans+=(a+1)*mul;
			if (b==1)
			{
				ans-=mul-(x%mul)-1;
			}
		}
		mul*=10;
	}
	cout << ans << endl;
	return 0;
}
