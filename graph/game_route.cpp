#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
vector<int> topo;
void dfs(vector<vector<int>> &adj,vector<int> &vis,int src){
    vis[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x]) dfs(adj,vis,x);
    }
    topo.push_back(src);
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int a,b;
    vector<int> vis(n+1,0);
    while(m--){
        cin>>a>>b;
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(adj,vis,i);
    }
    vector<int> t;int f = 0;
    for(int i=0;i<topo.size();i++){
        if(f == 0){
            if(topo[i] == 1){
                f  = 1;
                t.push_back(topo[i]);
            }
        }else t.push_back(topo[i]);
    }
    vector<int> path(n+1,0);
    path[1] = 1;
    for(auto i:t){
        for(auto j:adj[i]){
            (path[i]+=path[j])%=mod;
        }
    }
    cout<<path[n]<<endl;
}