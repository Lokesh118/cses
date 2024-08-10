#include<bits/stdc++.h>
using namespace std;
#define int long long
int M = 1e16;
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
    vector<vector<int>> a(n+1);
    vector<vector<int>> b(n+1);
    vector<tuple<int,int,int>> t;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        a[x].push_back(y);
        b[y].push_back(x);
        t.push_back({x,y,-z});
    }
    vector<int> v1(n+1,0),v2(n+1,0);
    dfs(a,v1,1);
    dfs(b,v2,n);
    vector<int> dist(n+1,M);
    int u,v,w;
    dist[1] = 0;
    for(int i=1;i<=n;i++){
        for(auto x:t){
            tie(u,v,w) = x;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u]+w;
                if(i==n && v1[u] && v2[v]){
                    cout<<-1;
                    return 0;;
                }
            }
            
        }
    }cout<<(-dist[n])<<endl;
}