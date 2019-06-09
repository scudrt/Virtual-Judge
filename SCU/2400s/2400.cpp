//simple
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
string s;
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		cin >> s;
		bool flag=false;
		int len=s.length();
		for (int i=0;i<len-3;++i)
			if (s[i]=='L' && s[i+1]=='O' && s[i+2]=='V' && s[i+3]=='E')
			{
				printf("LOVE\n");
				flag=true;
				break;
			}
		if (!flag)
			printf("SINGLE\n");
	}
	return 0;
}
