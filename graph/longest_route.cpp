#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(vector<vector<int>> &adj,vector<int> &vis,int src){
    vis[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x]) dfs(adj,vis,x);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<vector<int>> adj(n+1);
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> vis(n+1,0);
    dfs(adj,vis,1);
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
    dist[1] = 0;
    vector<int> par(n+1,-1);
    vector<int> vis1(n+1,0);
    while(!q.empty()){
        auto u  = q.top().second;q.pop();
        // if(vis1[u]) continue;
        // vis1[u] = 1;
        for(auto v:adj[u]){
            if(dist[v] > dist[u]-1){
                dist[v] = dist[u]-1;
                q.push({dist[v],v});
                par[v] = u;
            }
        }
    }
    cout<<(-dist[n]+1)<<endl;
    int t = n;
    vector<int> ans;
    while(t!=-1){
        ans.push_back(t);
        t = par[t];
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans) cout<<i<<" ";
}