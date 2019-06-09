#include <cstdio>
#include <cmath>
int n;
long long ans;
int euler(int x){
	int ret = x;
	if (!(x&1)){
		ret/=2;
		while ((x%2)==0){
			x/=2;
		}
	}
	int k = (int)sqrt(x);
	for (int i=3;i<=k;i+=2){
		if (x%i==0){
			ret=ret/i*(i-1);
			while (x%i==0){
				x/=i;
			}
		}
	}
	if (x-1){
		ret=ret/x*(x-1);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	int k = (int)sqrt(n);
	for (int i=1;i<=k;++i){
		int temp = n/i;
		if (temp*i == n){
			ans += euler(temp) * i;
			ans += euler(i) * temp;
		}
	}
	if (k*k == n){
		ans -= euler(k) * k;
	}
	printf("%lld\n",ans);
	return 0;
}
