#include <iostream>
#include <cstring>
using namespace std;
string s;
int ans;
bool yes(int len)
{
	for (int i=0;i<=s.length()-len;++i)
	{
		int j;
		for (j=i;j<i+len/2;++j)
		{
			if (s[i+len-1-j+i] != s[j])
				break;
		}
		if (j == i+len/2)
			return true;
	}
	return false;
}
int main()
{
	cin >> s;
	for (ans=s.length();ans>1;--ans)
	{
		if (yes(ans))
			break;
	}
	cout << ans << endl;
	return 0;
}
