#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50001;
int n,v,f[maxn],ans;
int w,p,c;
void update(){
	for (int i=1;i<c;i+=i){
		c-=i;
		int temp = i*w;
		for (int j=v;j>=temp;--j){
			if (f[j] < f[j-temp] + p*i){
				f[j] = f[j-temp] + p*i;
				ans = max(ans, f[j]);
			}
		}
	}
	if (c == 0){
		return;
	}
	int temp = c*w;
	for (int j=v;j>=temp;--j){
		if (f[j] < f[j-temp] + c*p){
			f[j] = f[j-temp] + c*p;
			ans = max(ans, f[j]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&v);
	for (int i=1;i<=n;++i){
		scanf("%d%d%d",&w,&p,&c);
		update();
	}
	printf("%d\n",ans);
	return 0;
}
