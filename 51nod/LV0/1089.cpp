//Manacher
#include <iostream>
#include <cstring>
using namespace std;
char s[200005];
int n,f[200005];
void deal()
{
	int right=0,pos=0;
	for (int i=1;i<=n;++i)
	{
		if (right>i)
		{
			f[i]=f[pos+pos-i];
			if (i+f[i]>=right)
			{
				int j;
				for (j=right-i;i+j<=n && i-j>=1;++j)
				{
					if (s[i+j] != s[i-j])
					{
						break;
					}
				}
				f[i]=j-1;
			}
		}
		else
		{
			int j;
			for (j=1;i+j<=n && i-j>=1;++j)
			{
				if (s[i+j]!=s[i-j])
				{
					break;
				}
			}
			f[i]=j-1;
		}
		if (f[0]<f[i])
			f[0]=f[i];
		if (i+f[i]>right)
		{
			pos=i;
			right=i+f[i];
		}
	}
}
int main()
{
	while (1)
	{
		s[++n]='!';
		s[++n]=getchar();
		if (s[n]=='\n')
		{
			--n;
			break;
		}
	}
	deal();
	cout << f[0] << endl;
	return 0;
}
