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
        if(rx - lx == 1){
            if(lx<(int)v.size()){
                sums[x] = v[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(v,2*x+1,lx,m);
        build(v,2*x+2,m,rx);
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }
    void build(vector<int> &v){
        build(v,0,0,size);
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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> v(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            v[i][j] = (c=='*');
        }
    }
    vector<segtree> st(n);
    for(int i=0;i<n;i++){
        st[i].init(n);
        st[i].build(v[i]);
    }
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int l = min(y1,y2);
        int r = max(y1,y2);
        int t = min(x1,x2);
        int b = max(x1,x2);
        int sum = 0;
        for(int i=t-1;i<b;i++){
            sum+=st[i].sum(l-1,r);
        }
        cout<<sum<<endl;
    }
}