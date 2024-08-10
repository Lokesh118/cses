#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree{
    int size;
    vector<int> sums;
    void init(int n){
        size = 1;
        while(size<n) size*=2;
        sums.assign(2*size,0LL);
    }
    void build(vector<int> &v,int x,int lx,int rx){
        if(rx-lx == 1){
            if(lx<(int)v.size()) sums[x] = v[lx];
            return;
        }
        int m = (lx+rx)/2;
        build(v,2*x+1,lx,m);
        build(v,2*x+2,m,rx);
        sums[x] = sums[2*x+1]^sums[2*x+2];
    }
    void build(vector<int> &v){
        build(v,0,0,size);
    }
    int sol(int l,int r,int x,int lx,int rx){
        if(l>=rx || lx>=r) return 0;
        if(lx>=l && rx<=r) return sums[x];
        int m = (lx+rx)/2;
        int x1 = sol(l,r,2*x+1,lx,m);
        int x2 = sol(l,r,2*x+2,m,rx);
        return x1^x2;
    }
    int sol(int l,int r){
        return sol(l,r,0,0,size);
    }
};
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    segtree st;
    st.init(n);
    st.build(v);
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<st.sol(l-1,r)<<endl;
    }
}