#include <iostream>
using namespace std;
int n,a[101][101],s[101][101],temp[101],ans;
void deal()
{
	for (int i=1;i<=n;++i)
	{
		for (int j=i;j<=n;++j)
		{
			for (int k=1;k<=n;++k)
			{
      //caculate the sum of lines from i to j
				temp[k]=s[j][k]-s[i-1][k];
			}
			int b[101]={0};
			for (int k=1;k<=n;++k)
			{
      //dynamic programming
				b[k]=temp[k];
				if (b[k-1]>0)
				{
					b[k]+=b[k-1];
				}
				if (ans<b[k])
				{
					ans=b[k];
				}
			}
		}
	}
}
int main()
{
	while (cin >> n)
	{
  //initializing
		ans=0x80000000;
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
			{
				cin >> a[i][j];
				s[i][j]=s[i-1][j]+a[i][j];
			}
		}
		deal();
		cout << ans << endl;
	}
	return 0;
}
