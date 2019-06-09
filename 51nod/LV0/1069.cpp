//I need to understand why is XOR.
#include <iostream>
using namespace std;
int n,a,b;
int main()
{
	cin >> n >> a;
	for (int i=2;i<=n;++i)
	{
		cin >> b;
		a=a^b;
	}
	if (a)
		cout << "A\n";
	else
		cout << "B\n";
	return 0;
}
