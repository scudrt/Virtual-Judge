#include <cstdio>
#include <cmath>
const int maxn = 1001;
int n,s[maxn];
void preDeal(){
	bool isprime[maxn]={0};
	for (int i=2;i<maxn;++i){
		isprime[i] = 1;
	}
	for (int i=2;i<maxn;++i)
		if (isprime[i]){
			for (int j=i*i;j<maxn;j+=i)
				isprime[j]=0;
			int k=i;
			while (k<maxn){
				++s[k];
				k *= i;
			}
		}
	for (int i=1;i<maxn;++i){
		s[i] += s[i-1];
	}
}
int main(){
	preDeal();
	scanf("%d",&n);
	if (n==1){
		printf("0\n");
	}else{
		printf("%d\n",s[n]);
	}
	return 0;
}
