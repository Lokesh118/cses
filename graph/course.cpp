#include<bits/stdc++.h>
using namespace std;
#define int long long

bool dfs(vector<vector<int>> &adj,vector<int> &vis,int src,vector<int> &v,vector<int> &stack){
    vis[src] = 1;
    stack[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x] && dfs(adj,vis,x,v,stack)) return true;
        else if(stack[x]) return true;
    }
    stack[src] = 0;
    v.push_back(src);
    return false;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int a,b;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> v;
    vector<int> vis(n+1,0);
    vector<int> stack(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(adj,vis,i,v,stack)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    reverse(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
}