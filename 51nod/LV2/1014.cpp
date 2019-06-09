#include <iostream>
#include <cmath>
using namespace std;
int a,s,p;
void deal()
{
	unsigned long long temp=a,limit=(unsigned long long)p*p;
	while (temp<=limit)
	{
		unsigned long long x=(int)sqrt(temp);
		if (x*x==temp)
		{
			++s;
			cout << x << ' ';
		}
		temp+=p;
	}
}
int main()
{
	cin >> p >> a;
	deal();
	if (s==0)
		cout << "No Solution";
	cout << '\n';
	return 0;
}
