#include <cstdio>
#define abs(x) ((x)>=0?(x):(-(x)))
const int maxn = 200001;
int n,temp,w,sum;
long long ans, a[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&temp,&w);
		a[temp+100000] += w;
		sum += w;
	}
	sum = (sum-1)/2 + 1;
	temp = w = 0;
	for (int i=0;i<maxn;++i){
		temp += a[i];
		if (temp >= sum){
			w = i;
			break;
		}
	}
	for (int i=0;i<maxn;++i){
		if (a[i]){
			ans += a[i] * abs(i - w);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
