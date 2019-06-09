//length of the product equal to 1+lg(1)+lg(2)...+lg(n) (take the integer part).
#include <iostream>
#include <cmath>
using namespace std;
int n;
double temp;
int main()
{
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		temp+=log10(i);
	}
	cout << (int)temp+1 << endl;
	return 0;
}
