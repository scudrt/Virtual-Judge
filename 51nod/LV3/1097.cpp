#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
string a[10001];
struct node
{
	string s,temp;
	bool operator <(const node&)const;
}t[10001];
bool node::operator<(const node& x)const
{
	return temp < x.temp;
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;++i)
	{
		 cin >> t[i].s;
		 t[i].temp=t[i].s;
		 while (t[i].temp.length() < 9)
		 {
		 	t[i].temp+=t[i].temp;
		 }
		 if (t[i].temp.length() > 9)
		 {
		 	t[i].temp=t[i].temp.substr(0,9);
		 }
	}
	sort(t+1,t+n+1);
	string ans=t[1].s;
	for (int i=2;i<=n;++i)
	{
		ans+=t[i].s;
	}
	int len=ans.length();
	int lena=len/1000;
	int lenb=len%1000;
	ans=' '+ans;
	for (int i=1;i<=lena;++i)
	{
		for (int j=(i-1)*1000+1;j<=i*1000;++j)
		{
			printf("%c",ans[j]);
		}
		printf("\n");
	}
	if (lenb)
		printf("%s\n",ans.substr(len-lenb+1,lenb).c_str());
	return 0;
}
