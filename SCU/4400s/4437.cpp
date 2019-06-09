#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct node{
	static int bit;
	int w;
	bool operator <(const node& x)const{
		return w%node::bit < x.w%node::bit;
	}
}t[maxn];
int node::bit = 10;
int n,k;
long long ans;
int main(){
	while (~scanf("%d",&n)){
		ans=k=0;
		node::bit = 10;
		for (int i=1;i<=n;++i){
			scanf("%d",&t[i].w);
			k = max(k, t[i].w);
		}
		while (node::bit <= k*10){
			sort(t+1,t+n+1);
			for (int i=1;i<n;++i){
				int l=i+1,r=n,mid;
				while (l<r){
					mid = (l+r)/2;
					if (t[mid].w%node::bit + t[i].w%node::bit >= node::bit){
						r=mid;
					}else{
						l = mid+1;
					}
				}
				if (t[l].w%node::bit + t[i].w%node::bit >= node::bit){
					ans += n-l+1;
				}
			}
			node::bit *= 10;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
