#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50001, inf = 0x7fffffff;
int n,c[maxn];
struct node{
	int w,rank;
	bool operator <(const node& x)const{
		return w==x.w?rank<x.rank:w<x.w;
	}
}t[maxn];
int lowbit(int x){
	return x&(-x);
}
void update(int pos, int x){
	while (pos <= n){
		c[pos] = min(x, c[pos]);
		pos += lowbit(pos);
	}
}
int query(int pos){
	int ret = inf;
	while (pos){
		ret = min(ret, c[pos]);
		pos -= lowbit(pos);
	}
	return ret;
}
int main(){
	int ans = 0;
	memset(c, 127, sizeof(c));
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&t[i].w);
		t[i].rank=i;
	}
	sort(t+1,t+n+1);
	for (int i=1;i<=n;++i){
		update(t[i].rank, t[i].rank);
		ans = max(ans, t[i].rank - query(n));
	}
	printf("%d\n",ans);
	return 0;
}
