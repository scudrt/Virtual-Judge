#include <cstdio>
const int maxn = 50001, maxm = 1000001;
int n,m,ans,a[maxn];
int hit[maxm];
int main(){
	int last=-1;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (a[i] > last){
			for (int j=last+1;j<=a[i];++j){
				hit[j] = i;
			}
			last = a[i];
		}
	}
	int temp;
	while (m--){
		scanf("%d",&temp);
		if (temp > last || temp <= a[1]){
			continue;
		}
		int k = hit[temp];
		++a[k-1];
		if (hit[a[k-1]] == k){
			hit[a[k-1]] = k-1;
		}
	}
	for (int i=1;i<=n;++i){
		printf("%d\n",a[i]);
	}
	return 0;
}
