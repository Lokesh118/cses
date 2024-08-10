#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree{
    int size;
    vector<int> sums;
    void init(int n){
        size = 1;
        while(size<n) size*=2;
        sums.assign(2*size,INT_MAX);
    }
    void build(vector<int> &v,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)v.size()){
                sums[x] = v[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(v,2*x+1,lx,m);
        build(v,2*x+2,m,rx);
        sums[x] = min(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<int> &v){
        build(v,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx == 1){
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        sums[x] = min(sums[2*x+1],sums[2*x+2]); 
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    int sol(int l,int r,int x,int lx,int rx){
        if(l>=rx || lx>=r) return INT_MAX;
        if(lx>=l && rx<=r) return sums[x];
        int m = (lx+rx)/2;
        int s1 = sol(l,r,2*x+1,lx,m);
        int s2 = sol(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }
    int sol(int l,int r){
        return sol(l,r,0,0,size);
    }
};
signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    segtree st;
    st.init(n);
    st.build(v);
    cout<<endl;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int i,v;
            cin>>i>>v;
            st.set(i-1,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.sol(l-1,r)<<endl;
        }
    }
}