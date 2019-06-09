#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500001;
int n,a[maxn];
int main(){
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	i=n/2+(n&1);
	j=n;
	while (i>=1){
		if (a[j] == -1){
			--j;
			continue;
		}
		if (a[i]*2 <= a[j]){
			a[i] = a[j] = -1;
			--j;
			--n;
		}
		--i;
	}
	printf("%d\n",n);
	return 0;
}
