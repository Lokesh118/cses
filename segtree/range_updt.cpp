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
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx == 1){
            sums[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    int sum(int l,int r,int x,int lx,int rx){
        if(l>=rx || r<=lx) return 0;
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
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    vector<int> diff = v;
    for(int i=1;i<n;i++){
        diff[i] = v[i]-v[i-1];
    }
    segtree st;
    st.init(n);
    st.build(diff);
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int l,r,u;
            cin>>l>>r>>u;
            st.set(l-1,u);
            if(r<n) st.set(r,-u);
        }else{
            int k;
            cin>>k;
            cout<<st.sum(0,k)<<endl;
        }
    }
}