#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    int prior;
    node* lson, *rson;
};
pair<node*, node* > spilt(node* u, int key){
    if(!u) return make_pair(nullptr, nullptr);
    if(key < u->key){
        pair<node*, node* > rec = spilt(u -> lson, key);
        u -> lson = rec.second;
        return make_pair(rec.first, u);
    } else{
        pair<node*, node* > rec = spilt(u -> rson, key);
        u -> rson = rec.first;
        return make_pair(u, rec.second);
    }
}
node* merge(node* a, node* b){
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    if(a -> prior > b -> prior){
        a -> rson = merge(a -> rson, b);
        return a;
    } else{
        b -> lson = merge(a, b -> lson);
        return b;
    }
}
int main(){
    
}