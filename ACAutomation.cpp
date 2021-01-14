#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define rep(i, a, b) for(int i = a; i <= b; i++)

int tr[maxn][26];
int tot;
int e[maxn], fail[maxn];
void insert(char* w){
    int u = 0;
    for(int i = 0; w[i]; i++){
        if(!tr[u][w[i] - 'a']) tr[u][w[i] - 'a'] = ++tot;
        u = tr[u][w[i] - 'a'];
    }
    e[u]++;
}
void build(){
    queue<int> q;
    rep(i, 0, 25) if(tr[0][i]) q.push(tr[0][i]);
    while(!q.empty()){
        int u = q.front(); q.pop();
        rep(i, 0, 25){
            if(tr[u][i]){
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
            } else{
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}
int query(char *t){
    int u = 0, res = 0;
    for(int i = 0; t[i]; i++){
        u = tr[u][t[i] - 'a'];
        for(int j = u; j && e[j] != -1; j = fail[j]){
            res += e[j]; e[j] = -1;
        }
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char w[maxn];
        scanf("%s", w);
        insert(w);
    }
    build();
    char t[maxn];
    scanf("%s", t);
    cout << query(t);
}
int main(){
    //int t;
    //cin >> t;
    //while(t--) 
    solve();
}