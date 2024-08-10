#include<bits/stdc++.h>
using namespace std;
vector<int> cyc;
bool dfs(vector<vector<int>> &adj,vector<int> &vis,int par,int src){
    vis[src] = 1;
    for(auto x:adj[src]){
        cyc.push_back(x);
        if(!vis[x]){
            if(dfs(adj,vis,src,x)) return true;
        }
        else if(x!=par) return true;
        cyc.pop_back();
    }
    return false;
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
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cyc.push_back(i);
            if(dfs(adj,vis,-1,i)){
                int i=0;
                while(cyc[i]!=cyc.back()) i++;
                cout<<cyc.size()-i<<endl;
                for(;i<cyc.size();i++) cout<<cyc[i]<<" ";
                return 0;
            }
            cyc.pop_back();
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}