#include <cstdio>
int t,sum;
char ch;
int main(){
	scanf("%d",&t);
	getchar();
	while (t--){
		sum=0;
		while (1){
			ch = getchar();
			if (ch == '\n'){
				break;
			}
			sum += ch-'0';
		}
		if (sum%3 == 0){
			printf("B\n");
		}else{
			printf("A\n");
		}
	}
	return 0;
}
