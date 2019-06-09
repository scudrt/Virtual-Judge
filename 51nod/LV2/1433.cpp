//The number of 5 should be 9*k,k>=0
//And there should be at least a 0.
#include <iostream>
#include <cstring>
using namespace std;
int n,five,zero;
string ans;
void deal()
{
	int tick=0;
	if (zero)
	{
		ans="0";
		--zero;
	}
	else
	{
		ans="-1";
		return;
	}
	while (five>=9)
	{
		five-=9;
		++tick;
	}
	if (tick)
	{
		for (int i=1;i<=zero;++i)
		{
			ans+="0";
		}
		for (int i=1;i<=tick;++i)
		{
			ans="555555555"+ans;
		}
	}
}
int main()
{
	int temp;
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		cin >> temp;
		if (temp)
			++five;
		else
			++zero;
	}
	deal();
	cout << ans << endl;
	return 0;
}
