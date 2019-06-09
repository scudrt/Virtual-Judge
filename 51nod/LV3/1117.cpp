#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
#define maxn 50001
priority_queue<int,vector<int>,greater<int> >q;
int n,m,t,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		int temp;
		scanf("%d",&temp);
		q.push(temp);
	}
	while (q.size() != 1){
		int temp = q.top();
		q.pop();
		temp += q.top();
		q.pop();
		q.push(temp);
		ans += temp;
	}
	printf("%d\n",ans);
	return 0;
}
