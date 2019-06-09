#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
struct node
{
    string s;
    int rank,v;
    bool operator <(const node&)const;
}t[101];
bool node::operator <(const node& x)const
{
    if (v<x.v)
        return true;
    else if (v==x.v && rank<x.rank)
        return true;
    return false;
}
void preDeal()
{
    for (int i=1;i<=n;++i)
        for (int j=0;j<m;++j)
            for (int k=j+1;k<m;++k)
                if (t[i].s[j]>t[i].s[k])
                    ++t[i].v;
}
int main()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;++i)
    {
        cin >> t[i].s;
        t[i].rank=i;
    }
    preDeal();
    sort(t+1,t+n+1);
    for (int i=1;i<=n;++i)
        cout << t[i].s << '\n';
    return 0;
}
