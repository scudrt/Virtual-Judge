#include <cstdio>
const int maxn = 100001, mod = 1000000007;
int n,a,last[maxn],f[maxn];
int main(){
	scanf("%d",&n);
	f[0] = 1;
	for (int i=1;i<=n;++i){
		scanf("%d",&a);
		f[i] += f[i-1]*2;
		if (last[a]){
			f[i] -= f[last[a]-1];
		}
		f[i] = (f[i]%mod+mod)%mod;
		last[a] = i;
	}
	printf("%d\n",f[n]-1);
	return 0;
}
