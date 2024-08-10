#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &adj,int src,vector<int> &vis){
    vis[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x]) dfs(adj,x,vis);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1);
    vector<vector<int>> b(n+1);
    int u,v;
    while(m--){
        cin>>u>>v;
        a[u].push_back(v);
        b[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    dfs(a,1,vis);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    for(int i=0;i<=n;i++) vis[i] = false;
    dfs(b,1,vis);
    int x = -1;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            x = i;
            break;
        }
    }
    if(x == -1){
        cout<<"YES\n";
        return 0;
    }
    for(int i=0;i<=n;i++) vis[i] = false;
    dfs(a,x,vis);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<x<<" "<<i<<endl;
            return 0;
        }
    }
}