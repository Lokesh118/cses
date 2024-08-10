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
    vector<int> in(n+1,0);
    vector<vector<int>> adj(n+1);
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    vector<int> vis(n+1,0);
    dfs(adj,vis,1);
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> dist(n+1,-1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0) q.push(i);
    }
    dist[1] = 0;
    vector<int> par(n+1,-1);
    while(!q.empty()){
        auto u  = q.front();q.pop();
        for(auto v:adj[u]){
            if(dist[u]!=-1 && dist[v]<dist[u]+1){
                dist[v] = dist[u]+1;
                par[v] = u;
            }
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    cout<<(dist[n]+1)<<endl;
    int t = n;
    vector<int> ans;
    while(t!=-1){
        ans.push_back(t);
        t = par[t];
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans) cout<<i<<" ";
}