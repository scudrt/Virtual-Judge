#include <iostream>
using namespace std;
#define LIMIT 2000000000 //2e9
int list[5843],n;
void preDeal(long long now)
{
	int l=1,r=list[0],mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (list[mid]<now)
			l=mid+1;
		else
			r=mid;
	}
	if (list[l]==now)
		return;
	++list[0];
	int i;
	for (i=list[0]-1;i>=1;--i)
	{
		if (list[i]>now)
			list[i+1]=list[i];
		else
		{
			break;
		}
	}
	list[i+1]=now;
	if (now*2<=LIMIT)
		preDeal(now*2);
	if (now*3<=LIMIT)
		preDeal(now*3);
	if (now*5<=LIMIT)
		preDeal(now*5);
	if (now*7<=LIMIT)
		preDeal(now*7);
}
inline void first()
{
	register int temp=n%10;
	cout << "The "<< n;
	if (n%100 >= 10 && n%100 <= 20)
		cout << "th";
	else if (temp==1)
		cout << "st";
	else if (temp==2)
		cout << "nd";
	else if (temp==3)
		cout << "rd";
	else
		cout << "th";
	cout << " humble number is ";
}
int main()
{
	preDeal(1);
	while (cin >> n)
	{
		if (n==0)
			break;
		first();
		cout << list[n] << ".\n";
	}
	return 0;
}
