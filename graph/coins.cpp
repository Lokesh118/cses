#include<bits/stdc++.h>
using namespace std;
#define int long long
stack<int> topo;
void dfs(vector<vector<int>> &adj,int src,vector<int> &vis){
    vis[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x]) dfs(adj,x,vis); 
    }
    topo.push(src);
}
void dfs(vector<vector<int>> &adj,int src,int k,vector<int> &vis,vector<int> &comp){
    comp[src] = k;
    vis[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x]) dfs(adj,x,k,vis,comp);
    }
}
int sol(vector<vector<int>> &adj3,int src,vector<int> &dp,vector<int> &grp){
    if(dp[src]) return dp[src];
    dp[src] = grp[src];
    for(auto x:adj3[src]){
        dp[src] = max(dp[src],grp[src]+sol(adj3,x,dp,grp));
    }
    return dp[src];
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<vector<int>> adj(n+1),adj2(n+1);
    int a,b;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);  
        adj2[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(adj,i,vis);
    }
    for(int i=1;i<=n;i++) vis[i]  = 0;
    int k = 0;
    vector<int> comp(n+1);
    vector<int> comps;
    while(!topo.empty()){
        auto x = topo.top();
        topo.pop();
        if(!vis[x]){
            k++;
            comps.push_back(k);
            dfs(adj2,x,k,vis,comp);
        }
    }
    int ans = 0;
    vector<int> grp(comps.size()+1,0);
    for(int i=1;i<=n;i++){
        grp[comp[i]]+=v[i];
    }
    vector<vector<int>> adj3(n+1);
    for(int i =1;i<=n;i++){
        for(auto j:adj[i]){
            if(comp[i]==comp[j]) continue;
            adj3[comp[i]].push_back(comp[j]);
        }
    }
    vector<int> dp(n+1,0);
    for(auto x:comps) ans = max(ans,sol(adj3,x,dp,grp));
    cout<<ans<<endl;
}