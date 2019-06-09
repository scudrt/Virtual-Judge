#include <iostream>
using namespace std;
int n,s,ans,*a,sum;
void deal()
{
	int temp=0,avg=sum/s; //temp is the rest cards in the hand(could be negative)
	for (int i=1;i<=s;++i)
	{
		if (temp+a[i]==avg)
		{
			temp=0;
			continue;
		}
		else
		{
      //move the cards
			temp+=a[i]-avg;
			++ans;
		}
	}
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		ans=sum=0;
		cin >> s; //number of cards
		a=new int[s+1]; //a is the array for cards
		for (int j=1;j<=s;++j)
		{
			cin >> a[j];
			sum+=a[j];
		}
		deal();
		cout << ans << endl;
		delete[] a;
	}
	return 0;
}
