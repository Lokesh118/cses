#include<bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> mins;
    void init(int n){
        size = 1;
        while(size<n) size*=2;
        mins.assign(2*size,INT_MAX);
    }
    void build(vector<int> &a,int x,int lx,int rx){
        if(rx-lx == 1){
            if(lx<(int)a.size()){
                mins[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        mins[x] = min(mins[2*x+1],mins[2*x+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    int sol(int l,int r,int x,int lx,int rx){
        if(lx>=r || l>=rx) return INT_MAX;
        if(lx>=l && rx<=r) return mins[x];
        int m = (lx+rx)/2;
        int m1 = sol(l,r,2*x+1,lx,m);
        int m2 = sol(l,r,2*x+2,m,rx);
        return min(m1,m2);
    }
    int sol(int l,int r){
        return sol(l,r,0,0,size);
    }
};
int main(){
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

