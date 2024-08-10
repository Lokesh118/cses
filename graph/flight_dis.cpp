#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    vector<vector<pair<int,int>>> a(n+1);
    vector<vector<pair<int,int>>> b(n+1);
    vector<tuple<int,int,int>> t;
    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        b[v].push_back({u,w});
        t.push_back({u,v,w});
    }
    vector<int> dis1(n+1,inf);
    vector<int> dis2(n+1,inf);
    dks(a,1,dis1);
    dks(b,n,dis2);
    int ans = inf;
    for(auto x:t){
        tie(u,v,w) = x;
        ans = min(ans,dis1[u]+dis2[v]+w/2);
    }
    cout<<ans<<endl;
}