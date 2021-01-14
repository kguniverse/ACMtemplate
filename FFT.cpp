#include<bits/stdc++.h>
using namespace std;
#define io ios::sync_with_stdio(false); cin.tie(0);
#define maxn 3000100
#define pi acos(-1.0)

typedef complex<double> comp;
//struct comp{
//    double x, y;
//    comp (double xx = 0, double yy = 0){
//        x = xx; y = yy;
//    }
//    double real(){return x;}
//};
//comp operator * (comp J, comp Q){
//    return comp(J.x * Q.x - J.y * Q.y , J.x * Q.y + J.y * Q.x);
//}
//comp operator + (comp J, comp Q){
//    return comp(J.x + Q.x , J.y + Q.y);
//}
//comp operator - (comp J, comp Q){
//    return comp(J.x - Q.x , J.y - Q.y );
//}
comp A[maxn], B[maxn];
int lim = 1, L;
int R[maxn];
int aws[maxn];

void fft(comp* a, double flag){
    for(int i = 0; i < lim; i++){
        if(i < R[i]) swap(a[i], a[R[i]]);
    }
    for(int j = 1; j < lim; j <<= 1){
        comp t(cos(pi / j), flag * sin(pi / j));
        for(int k = 0; k < lim; k += (j << 1)){
            comp w(1, 0);
            for(int l = 0; l < j; l++, w = w * t){
                comp nx = a[k + l], ny = w * a[k + j + l];
                a[k + l] = nx + ny;
                a[k + l + j] = nx - ny;
            }
        }
    }
}
int main(){
    io
    string a, b;
    cin >> a >> b;
    lim = 1;
//    for(int i = 0; i < a.size(); i++) A[i] = {static_cast<double>(a[i] - '0'), 0};
//    for(int i = 0; i < b.size(); i++) B[i] = {static_cast<double>(b[i] - '0'), 0};
    int AA = 0, BB = 0;
    for(int i = a.size() - 1; i >= 0; i--) A[AA++].real(a[i] - 48);
    for(int i = b.size() - 1; i >= 0; i--) B[BB++].real(b[i] - 48);
    while(lim < a.size() + b.size()) lim <<= 1, L++;
    for(int i = 0; i <= lim; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    fft(A, 1); fft(B, 1);
    for(int i = 0; i <= lim; i++) A[i] = A[i] * B[i];
    fft(A, -1);
    for(int i = 0; i <= lim; i++){
        aws[i] += (int)(A[i].real() / lim + 0.5);
        if(aws[i] > 10) aws[i + 1] += aws[i] / 10, aws[i] %= 10, lim += (i == lim);
    }
    while(!aws[lim] && lim >= 1) lim--;
    lim++;
    while(--lim >= 0) cout << aws[lim];
}