#include <cstdio>
int main(){
	int t,n,a,b,d,ans=0;
	scanf("%d",&t);
	while (t--){
		ans = 0;
		scanf("%d%d%d%d",&a,&b,&d,&n);
		if (n == 1){
			a*=b;
			if (a%10 == d) ++ans;
			if (a/10 == d && a>=10) ++ans;
			printf("%d\n",ans);
		}else{
			int c[4];
			a *= 111*b;
			c[0] = a/1000;
			c[1] = a/100%10;
			c[2] = a/10%10;
			c[3] = a%10;
			if (c[0] == d && c[0] != 0) ++ans;
			if (c[1] == d) ans += n-2;
			if (c[2] == d) ++ans;
			if (c[3] == d) ++ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
