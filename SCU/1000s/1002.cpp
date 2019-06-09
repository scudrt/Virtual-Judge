#include <iostream>
#include <cstring>
using namespace std;
int a[502],b[502];  //don't forget the length may increase
string numa,numb;
void deal()
{
//transform the string into the int array
    for (int i=1;i<=501;++i)
    {
        a[i]=b[i]=0;
    }
    int temp=numa.length();
    for (int i=1;i<=temp;++i)
    {
        a[temp-i+1]=numa[i-1]-48;
    }
    temp=numb.length();
    for (int i=1;i<=temp;++i)
    {
        b[temp-i+1]=numb[i-1]-48;
    }
}
void add()
{
    int temp=numa.length();
    if (temp<numb.length())
    {
        temp=numb.length();
    }
    for (int i=1;i<=temp;++i)
    {
        a[i]+=b[i];
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    if (a[temp+1])
    {
        ++temp;
    }
}
int main()
{
    while (cin >> numa >> numb)
    {
        deal();
        add();
        //output
        for (int i=temp;i>=1;--i)
        {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
