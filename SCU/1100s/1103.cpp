//ugly problem
#include <iostream>
#include <cstring>
using namespace std;
string s;
bool yes;
int main()
{
	while (cin >> s)
	{
		int len=s.length(),now,tick=0;
		bool numgot;

		s=' '+s;
		now=0;
		yes=true;
		numgot=false;

		for (int i=1;i<=len;++i)
		{
			if (s[i]>='0' && s[i]<='9')
			{
				numgot=true;
				now=now*10+s[i]-'0';
				if (now>255)
				{
					yes=false;
					break;
				}
			}
			else if (s[i]=='.')
			{
				if (!numgot)
				{
					yes=false;
					break;
				}
				++tick;
				if (tick>3)
				{
					yes=false;
					break;
				}
				now=0;
				numgot=false;
			}
			else
			{
				yes=false;
				break;
			}
		}
		if (tick != 3 || (!numgot))
			yes=false;
		if (yes)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
