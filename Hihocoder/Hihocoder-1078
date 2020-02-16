/*
hihocoder-1078
线段树区间修改模板
使用了ID函数优化
*/
#include <cstdio>
const int maxn = 100005;

class Node{
public:
    int value, lazy;
    int len;
}t[maxn * 2];

int n, q;
int ql, qr, value;

inline int id(int l, int r){
    return (l+r) | (l!=r);
}

inline void pushdown(int l, int mid, int r){
    int now = id(l, r), left = id(l, mid), right = id(mid+1, r);
    int lazy = t[now].lazy;
    t[now].lazy = 0;
    t[left].lazy = lazy;
    t[right].lazy = lazy;
    t[left].value = lazy * t[left].len;
    t[right].value = lazy * t[right].len;
}

int build(int l, int r){
    int now = id(l, r);
    t[now].len = r - l + 1;
    if (l == r){
        scanf("%d", &t[now].value);
        return t[now].value;
    }
    int mid = (l+r) >> 1;
    return t[now].value = build(l, mid) + build(mid+1, r);
}

void update(int l, int r){
    int now = id(l, r);
    if (ql <= l && r <= qr){
        t[now].value = value * (r - l + 1);
        t[now].lazy = value;
        return;
    }
    int mid = (l+r) >> 1, left = id(l, mid), right = id(mid+1, r);
    if (t[now].lazy){
        pushdown(l, mid, r);
    }
    if (ql <= mid){
        update(l, mid);
    }
    if (qr > mid){
        update(mid+1, r);
    }
    t[now].value = t[id(l, mid)].value + t[id(mid+1, r)].value;
}

int query(int l, int r){
    int now = id(l, r);
    if (ql <= l && r <= qr){
        return t[now].value;
    }
    int mid = (l+r) >> 1, ret = 0;
    if (t[now].lazy){
        pushdown(l, mid, r);
    }
    if (ql <= mid){
        ret += query(l, mid);
    }
    if (qr > mid){
        ret += query(mid+1, r);
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    build(1, n);

    int code;
    scanf("%d", &q);
    while (q--){
        scanf("%d", &code);
        if (code){
            scanf("%d%d%d", &ql, &qr, &value);
            update(1, n);
        }else{
            scanf("%d%d", &ql, &qr);
            printf("%d\n", query(1, n));
        }
    }
    return 0;
}
