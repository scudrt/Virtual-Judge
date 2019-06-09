#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1005;
int f[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.length();
	s = ' ' + s;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (s[i] == s[n-j+1]){
				f[i][j] = f[i-1][j-1] + 1;
			}else{
				f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
	}
	cout << n - f[n][n] << '\n';
	return 0;
}
