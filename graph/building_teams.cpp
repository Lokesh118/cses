#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &col,int src,int c){
    vis[src] = true;
    col[src] = c;
    for(auto x:adj[src]){
        if(!vis[x]){
            if(dfs(adj,vis,col,x,c^1) == false) return false;
        }else if(col[src] == col[x]) return false;
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(n+1,false);
    vector<int> col(n+1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(adj,vis,col,i,0) == false){
                cout<<"IMPOSSIBLE"<<endl;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<col[i]+1<<" ";
}