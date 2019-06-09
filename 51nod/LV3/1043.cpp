#include <iostream>
using namespace std;
#define MOD 1000000007
long long n,ans;
int f1[1001][9001],f2[1001][9001];
void deal()
{
    for (int i=1;i<=9;++i)
        f1[1][i]=f2[1][i]=1;
    f2[1][0]=1;
    for (int i=1;i<n;++i)
    {
        for (int k=0;k<=9;++k)
            f2[i+1][k]=(f2[i+1][k]+f2[i][0])%MOD;
        for (int j=1;j<=9*i;++j)
            for (int k=0;k<=9;++k)
            {
                f1[i+1][j+k]=(f1[i+1][j+k]+f1[i][j])%MOD;
                f2[i+1][j+k]=(f2[i+1][j+k]+f2[i][j])%MOD;
            }
    }
    for (int i=1;i<=n*9;++i)
    {
        long long temp=f1[n][i];
        temp=temp*f2[n][i]%MOD;
        ans=(ans+temp)%MOD;
    }
}
int main()
{
    cin >> n;
    deal();
    cout << ans << endl;
    return 0;
}
