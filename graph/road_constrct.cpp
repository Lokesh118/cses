#include<bits/stdc++.h>
using namespace std;
int ans = 1;
int comp;
int find(vector<int> &rep,int u){
    if(u == rep[u]) return u;
    else return rep[u] = find(rep,rep[u]);
}
void combine(vector<int> &size,vector<int> &rep,int u,int v){
    u = find(rep,u);
    v = find(rep,v);
    if(u == v) return;
    else{
        comp--;
        if(size[u]>size[v]){
            rep[v] = u;
            size[u]+=size[v];
            ans = max(ans,size[u]);
        }else{
            rep[u] = v;
            size[v]+=size[u];
            ans = max(ans,size[v]);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    comp = n;
    vector<int> size(n+1,1);
    vector<int> rep(n+1);
    for(int i=1;i<=n;i++) rep[i] = i;
    int a,b;
    while(m--){
        cin>>a>>b;
        combine(size,rep,a,b);
        cout<<comp<<" "<<ans<<endl;
    }
}