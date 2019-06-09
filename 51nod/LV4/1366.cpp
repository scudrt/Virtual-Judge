#include <cstdio>
const int maxn = 51, inf = 0x3f3f3f3f;
int t,n,d,fa[maxn];
int map[maxn][maxn];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main()
{
	scanf("%d",&t);
	while (t--){
		int ans = 0, tick;
		scanf("%d%d",&n,&d);
		tick = n;
		getchar();
		char ch;
		for (int i=1;i<=n;++i){
			fa[i] = i;
		}
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				scanf("%c",&ch);
				if (ch == 'Y'){
					map[i][j] = 1;
					int a=getfa(i),b=getfa(j);
					if (a != b){
						fa[a] = b;
						--tick;
					}
				}else{
					map[i][j] = inf;
				}
			}
			getchar();
		}
		for (int k=1;k<=n;++k){
			for (int i=1;i<=n;++i){
				for (int j=1;j<=n;++j){
					if (map[i][j] > map[i][k] + map[k][j]){
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		for (int i=1;i<=n;++i){
			for (int j=i+1;j<=n;++j){
				if (map[i][j] != inf && ans < map[i][j]){
					ans = map[i][j];
				}
			}
		}
		if (tick == 1){
			printf("%d\n",ans * d);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
