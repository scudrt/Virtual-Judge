#include <cstdio>
long long a,b;
long long get(long long x, int k){
	long long ret = 0, weight = 1;
	while (weight <= x){
		int bit = x/weight%10;
		ret += weight * (x / (weight*10));
		if (bit > k){
			ret += weight;
		}else if (bit == k){
			ret += x % weight + 1;
		}
		if (k==0){
			ret -= weight;
		}
		weight*=10;
	}
	return ret;
}
int main(){
	scanf("%lld%lld",&a,&b);
	for (int i=0;i<=9;++i){
		printf("%lld\n",get(b,i)-get(a-1,i));
	}
	return 0;
}
