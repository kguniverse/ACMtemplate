#include<bits/stdc++.h>
using namespace std;
#define maxn 200010

int cnt, q, p;
int tr[maxn << 5], ls[maxn << 5], rs[maxn << 5];
int a[maxn], b[maxn], rk[maxn];

void build(int& rw, int l, int r){
    rw = ++cnt; tr[rw] = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(ls[rw], l, mid); build(rs[rw], mid + 1, r);
}
int update(int rw, int l, int r){
    int kw = ++cnt;
    ls[kw] = ls[rw]; rs[kw] = rs[rw];
    tr[kw] = tr[rw] + 1;
    int mid = (l + r) >> 1;
    if(l == r) return kw;
    if(p <= mid){
        ls[kw] = update(ls[rw], l, mid);
    } else{
        rs[kw] = update(rs[rw], mid + 1, r);
    }
    return kw;
}
int query(int u, int v, int l, int r, int k){
    int x = tr[ls[v]] - tr[ls[u]];
    int mid = (l + r) >> 1;
    if(l == r) return l;
    if(x >= k) return query(ls[u], ls[v], l, mid, k);
    else return query(rs[u], rs[v], mid + 1, r, k - x);
}
int main(){
//    freopen("P3834_3.in","r",stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memcpy(b, a, sizeof(a));
    sort(b + 1, b + 1 + n);
    q = unique(b + 1, b + 1 + n) - b - 1;
    build(rk[0], 1, q);
    for(int i = 1; i <= n; i++){
        p = lower_bound(b + 1, b + 1 + q, a[i]) - b;
        rk[i] = update(rk[i - 1], 1, q);
    }
    for(int i = 1; i <= m; i++){
        int u, v, k;
        cin >> u >> v >> k;
        cout << b[query(rk[u - 1], rk[v], 1, q, k)] << endl;
    }
}