#include <iostream>
using namespace std;
int x,ans;
int main()
{
	cin >> x;
	while (x)
	{
		ans=ans>x%10?ans:x%10;
		x/=10;
	}
	cout << ans << endl;
	return 0;
}
