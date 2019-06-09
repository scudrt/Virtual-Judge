#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50001, maxm = 50001;
int n,m,a[maxn];
priority_queue<int, vector<int>,greater<int> >q;
struct node{
	int d,w;
	bool operator <(const node& x)const{
		return d<x.d;
	}
}t[maxm];
int main(){
	long long ans = 0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=m;++i){
		scanf("%d%d",&t[i].d,&t[i].w);
	}
	sort(a+1,a+n+1);
	sort(t+1,t+m+1);
	int j=m;
	for (int i=n;i>=1;--i){
		while (t[j].d >= a[i] && j >= 1){
			q.push(t[j].w);
			--j;
		}
		if (q.size() == 0){
			ans = -1;
			break;
		}
		int k = q.top();
		q.pop();
		ans += k;
	}
	if (ans+1){
		printf("%lld\n",ans);
	}else{
		printf("No Solution\n");
	}
	return 0;
}
