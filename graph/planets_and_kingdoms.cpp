#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj,int src,vector<int> &vis,stack<int> &topo){
    vis[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x]) dfs(adj,x,vis,topo);
    }
    topo.push(src);
}
void dfs2(vector<vector<int>> &adj,int src,vector<int> &vis,int c){
    vis[src] = c;
    for(auto x:adj[src]){
        if(!vis[x]) dfs2(adj,x,vis,c);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1),b(n+1);
    int u,v;
    while(m--){
        cin>>u>>v;
        a[u].push_back(v);
        b[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    stack<int> topo;
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(a,i,vis,topo);
    }
    for(int i=0;i<=n;i++) vis[i] = 0;
    int c = 0;
    while(!topo.empty()){
        int x = topo.top();topo.pop();
        if(!vis[x]){
            c++;
            dfs2(b,x,vis,c);
        }
    }
    cout<<c<<endl;
    for(int i=1;i<=n;i++) cout<<vis[i]<<" ";

}