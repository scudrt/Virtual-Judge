//matrix multiplication(n*n)
#include <iostream>
using namespace std;
int n,m[3][101][101];
void deal()
{
	int temp[101][101]={0};
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			for (int k=1;k<=n;++k)
			{
				temp[j][i]+=m[1][j][k]*m[2][k][i];
			}
		}
	}
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			m[1][i][j]=temp[i][j];
		}
	}
}
int main()
{
	cin >> n;
	for (int k=1;k<=2;++k)
	{
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
			{
				cin >> m[k][i][j];
			}
		}
	}
	deal();
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=n;++j)
		{
			cout << m[1][i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
