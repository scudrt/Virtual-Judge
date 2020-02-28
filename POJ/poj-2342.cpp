/*
POJ-2342
树形DP
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 6005;
int nex[maxn], head[maxn], v[maxn], sum = 0;
int n, a, b, fa[maxn], dp[maxn][2];

void add(int a, int b){
    nex[++sum] = head[a];
    head[a] = sum;
    v[sum] = b;
}

void search(int now){
    for (int i=head[now];i;i=nex[i]){
        int to = v[i];
        search(to);
        dp[now][0] += max(dp[to][0], dp[to][1]);
        dp[now][1] += dp[to][0];
    }
}

int main(){
    while (~scanf("%d", &n)){
        sum = 0;
        for (int i=1;i<=n;++i){
            fa[i] = head[i] = dp[i][0] = 0;
            scanf("%d", &dp[i][1]);
        }
        while (scanf("%d%d", &a, &b),a+b){
            fa[a] = b;
            add(b, a);
        }
        for (int i=1;i<=n;++i){
            if (fa[i] == 0){
                search(i);
                printf("%d\n", max(dp[i][0], dp[i][1]));
                break;
            }
        }
    }
    return 0;
}
