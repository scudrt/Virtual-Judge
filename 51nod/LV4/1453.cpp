#include <cstdio>
const int maxn = 1005, mod = 1000000007;
int n,a,num;
long long ans,c[maxn][maxn]={1};
int main(){
	ans = 1;
	for (int i=1;i<maxn;++i){
		c[i][0] = 1;
		for (int j=1;j<=i;++j){
			c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
		}
	}
	scanf("%d%d",&n,&num);
	for (int i=2;i<=n;++i){
		scanf("%d",&a);
		num += a-1;
		ans = ans*c[num][a-1]%mod;
		++num;
	}
	printf("%lld\n",ans);
	return 0;
}
