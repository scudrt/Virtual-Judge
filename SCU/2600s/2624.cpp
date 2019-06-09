#include <iostream>
#include <cstring>
using namespace std;
string s;
int main()
{
    while (cin >> s)
    {
        if (s[0]=='0')
            break;
        for (int i=0;i<=s.length()/2;++i)
            if (s[i]!=s[s.length()-i-1])
            {
                printf("no\n");
                s[0]='-';
                break;
            }
        if (s[0]!='-')
            printf("yes\n");
    }
    return 0;
}
