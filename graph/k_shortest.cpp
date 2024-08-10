#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);
    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<vector<int>> dist(n+1,vector<int> (k,1e16));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dist[1][0] = 0;
    q.push({0,1});
    while(!q.empty()){
        auto t = q.top();q.pop();
        int u = t.second;
        int c = t.first;
        if(dist[u][k-1] < c) continue;
        for(auto x:adj[u]){
            int v = x.first;
            int w = x.second;
            if(dist[v][k-1] > c+w){
                dist[v][k-1] = c+w;
                sort(dist[v].begin(),dist[v].end());
                q.push({c+w,v});
            }
        }
    }
    for(int i=0;i<k;i++) cout<<dist[n][i]<<" ";
}