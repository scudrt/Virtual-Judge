#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100005;
const double inf = 999999999;

int n;
struct node{
    double x, y;
    bool operator <(const node& other){
        return x == other.x ? y < other.y : x < other.x;
    }
}t[maxn];

double go(int l, int r){
    double a, b, ret = inf;
    if (r <= l+2){
        for (int i=l;i<r;++i){
            for (int j=i+1;j<=r;++j){
                a = t[i].x - t[j].x;
                b = t[i].y - t[j].y;
                ret = min(ret, sqrt(a*a + b*b));
            }
        }
        return ret;
    }
    int mid = (l+r) >> 1, k = min(r, mid+6);
    ret = min(go(l, mid), go(mid+1, r));
    for (int i=l;i<=mid;++i){
        for (int j=mid+1;j<=k;++j){
            a = t[i].x - t[j].x;
            b = t[i].y - t[j].y;
            ret = min(ret, sqrt(a*a + b*b));
        }
    }
    return ret;
}

int main(){
    while (scanf("%d",&n),n){
        for (int i=1;i<=n;++i){
            scanf("%lf%lf", &t[i].x, &t[i].y);
        }
        sort(t+1, t+n+1);
        printf("%.2lf\n", go(1, n) / 2);
    }
    return 0;
}
