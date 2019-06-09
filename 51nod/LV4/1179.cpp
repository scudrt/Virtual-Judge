#include <cstdio>
#include <cmath>
const int maxn = 50001, maxm = 1000001;
int tick[maxm],a,n,ans=1;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a);
		int k = (int)sqrt(a);
		if (a&1){
			for (int i=1;i<=k;i+=2){
				if ((a%i)==0){
					++tick[i];
					if (i*i != a){
						++tick[a/i];
					}
				}
			}
		}else{
			for (int i=1;i<=k;++i){
				if ((a%i)==0){
					++tick[i];
					if (i*i != a){
						++tick[a/i];
					}
				}
			}
		}
	}
	tick[1] = 2;
	for (int i=maxm-1;i>=1;--i){
		if (tick[i] >= 2){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
