#include <cstdio>
long long ans;
int n;
int main(){
	while (~scanf("%d",&n)){
		if (n <= 2){
			printf("%d\n",n);
			continue;
		}
		ans = n;
		ans *= n-1;
		if (n&1){
			ans *= (n-2);
		}else{
			ans *= (n-3);
			if (n%3==0){
				ans = ans / n * (n-2);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
