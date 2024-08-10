#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adj,vector<int> &vis,int src){
    vis[src] = 1;
    for(auto i:adj[src]){
        if(!vis[i]) dfs(adj,vis,i);
    }
}
int main(){
    int n,r;
    cin>>n>>r;
    vector<vector<int>> adj(n+1);
    while(r--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> ans;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(adj,vis,i);
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[0]<<" "<<ans[i]<<endl;
    }
    return 0;
}