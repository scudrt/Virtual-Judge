#include <iostream>
#include <string>
using namespace std;
int ans=0x7fffffff,n;
string s;
struct node
{
    int ch[26];
    node operator -(const node&)const;
}t[100001];
node node::operator -(const node& x)const
{
    node temp;
    for (int i=0;i<26;++i)
        temp.ch[i]=ch[i]-x.ch[i];
    return temp;
}
bool suit(node x)
{
    for (int i=0;i<26;++i)
        if (!x.ch[i])
            return false;
    return true;
}
bool ok(int len)
{
    for (int i=1;i<=n-len+1;++i)
        if (suit(t[i+len-1]-t[i-1]))
            return true;
    return false;
}
void deal()
{
    int l=1,r=n,mid;
    while (l<r)
    {
        mid=(l+r)>>1;
        if (ok(mid))
            r=mid;
        else
            l=mid+1;
    }
    if (ok(l))
        ans=l;
}
int main()
{
    cin >> s;
    n=s.length();
    s=' '+s;
    for (int i=1;i<=n;++i)
    {
        t[i]=t[i-1];
        ++t[i].ch[s[i]-'A'];
    }
    deal();
    if (ans==0x7fffffff)
        cout << "No Solution\n";
    else
        cout << ans << endl;
    return 0;
}
