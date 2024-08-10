#include<bits/stdc++.h>
using namespace std;
#define int long long
int inf = 1e16;
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> par(n+1,-1);
    vector<int> cost(n+1,inf);
    vector<int> mst(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
    cost[1] = 0;
    while(!q.empty()){
        u = q.top().second;
        q.pop();
        if(mst[u]) continue;
        mst[u] = 1;
        for(auto x:adj[u]){
            v = x.first;
            w = x.second;
            if(!mst[v] && cost[v]>w){
                cost[v] = w;
                q.push({cost[v],v});
                par[v] = u;
            }
        }
    }
    int ans = 0;
    int flg = 0;
    for(int i=1;i<=n;i++){
        if(cost[i] == inf){
            flg = 1;
            break;
        }
        ans+=cost[i];
    }
    if(flg){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<ans<<endl;
}