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
    void build(vector<int> &a,int x,int lx,int rx){
        if(rx-lx == 1){
            if(lx<(int)a.size()){
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    int sum(int l,int r,int x,int lx,int rx){
        if(lx>=r || l>=rx) return 0;
        if(lx>=l && rx<=r) return sums[x];
        int m = (lx+rx)/2;
        int s1 = sum(l,r,2*x+1,lx,m);   
        int s2 = sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    int sum(int l,int r){
        return sum(l,r,0,0,size);
    }
};
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    segtree st;
    st.init(n+1);
    st.build(v);
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<st.sum(l-1,r)<<endl;
    }
}