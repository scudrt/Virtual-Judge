#include <cstdio>
int t,n;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		n%=7;
		if (n==0 || n==2){
			printf("B\n");
		}else{
			printf("A\n");
		}
	}
	return 0;
}
