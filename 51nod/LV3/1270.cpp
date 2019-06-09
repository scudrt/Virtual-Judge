#include <stdio.h>
#include <algorithm>
using namespace std;
#define abs(x) (-(x))
#define maxn 50001

int f[maxn][2],a[maxn],n;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=2;i<=n;++i){
		f[i][0] = f[i-1][1] + a[i-1] - 1;
		f[i][1] = max(f[i-1][0] + a[i] - 1, f[i-1][1] + abs(a[i] - a[i-1]));
	}
	printf("%d\n",max(f[n][0],f[n][1]));
	return 0;
}
