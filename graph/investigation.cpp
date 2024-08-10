#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int inf = 1e16;
void dks(vector<vector<pair<int,int>>> &adj,int src,vector<int> &dis){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dis[src] = 0;
    q.push({0,src});
    vector<int> vis(adj.size(),0);
    while(!q.empty()){
        auto u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto x:adj[u]){
            int v = x.first;
            int w = x.second;
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int> dist(n+1,inf);
    dks(adj,1,dist);
    vector<vector<int>> b(n+1);
    vector<int> in(n+1,0);
    for(int u=1;u<=n;u++){
        for(auto x:adj[u]){
            int v = x.first;
            int w = x.second;
            if(dist[v] == dist[u]+w){
                in[v]++;
                b[u].push_back(v);
            }
        }
    }
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        u = q.front();q.pop();
        for(auto v:b[u]){
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    q.push(1);
    vector<int> mx(n+1,0),mn(n+1,INT_MAX),path(n+1,0);
    path[1] = 1;
    mn[1] = 0;
    mx[1] = 0;
    while(!q.empty()){
        auto u = q.front();q.pop();
        for(auto v:b[u]){
            in[v]--;
            (path[v]+=path[u])%=mod;
            if(mx[v]<mx[u]+1) mx[v] = mx[u]+1;
            if(mn[v]>mn[u]+1) mn[v] = mn[u]+1;
            if(in[v]==0) q.push(v);
        }
    }
    cout<<dist[n]<<" "<<(path[n]%mod)<<" "<<mn[n]<<" "<<mx[n]<<endl;
}