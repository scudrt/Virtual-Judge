//monotone stack
//r[0],l represent the number of the rest right fish and left fish
#include <iostream>
using namespace std;
int l,r[100001],n;
int main()
{
	cin >> n;
	while (n--)
	{
		int a,b;
		cin >> a >> b;
		if (b) //right fish
			r[++r[0]]=a;
		else //left fish
		{
			if (r[0])
			{
				while (r[0] && r[r[0]]<a)
					--r[0];
				if (r[0]==0)
					++l;
			}
			else
				++l;
		}
	}
	cout << l+r[0] << endl;
	return 0;
}
