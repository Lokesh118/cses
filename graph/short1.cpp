#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        adj[x].push_back({y,c});
    }
    vector<int> dist(n+1,LLONG_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[1] = 0;
    pq.push({0,1});
    vector<int> vis(n+1,0);
    while(!pq.empty()){
        auto u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto x:adj[u]){
            int v = x.first;
            int c = x.second;
            if(dist[v] > dist[u]+c){
                dist[v] = dist[u]+c;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i = 1;i<=n;i++) cout<<dist[i]<<" ";
}