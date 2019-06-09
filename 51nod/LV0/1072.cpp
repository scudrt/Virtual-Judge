#include <cstdio>
#include <cmath>
const double p = (1+sqrt(5))/2;
int main(){
	int t,a,b;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&a,&b);
		if (a==b && b==0){
			printf("B\n");
			continue;
		}
		if (a>b){
			a^=b^=a^=b;
		}
		int k=b-a;
		if ((int)(k*p) == a){
			printf("B\n");
		}else{
			printf("A\n");
		}
	}
	return 0;
}
