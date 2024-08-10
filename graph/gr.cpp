#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int a,b;
    vector<int> in(n+1,0);
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(in[i] == 0) q.push(i); 
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v:adj[u]){
            in[v]--;
            if(in[v] == 0 && v!=1) q.push(v);
        }
    }
    q.push(1);
    vector<int> path(n+1,0);
    path[1] = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v:adj[u]){
            in[v]--;
            (path[v]+=path[u])%=mod;
            if(in[v]==0) q.push(v);
        }
    }
    cout<<path[n]<<endl;
}