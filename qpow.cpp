#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll qpow(int x, int y, int m){
    if(y == 0) return 1;
    ll res = 1;
    while(y){
        if(y & 1) res = (1ll * res * x) % m;
        x = (1ll * x * x) % m, y >>= 1;
    }
    return res;
}