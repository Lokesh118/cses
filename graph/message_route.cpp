#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
bool bfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> vis(n+1,false);
    queue<int> q;
    q.push(1);
    vector<int> par(n+1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x==n-1){
            while(x!=1){
                ans.push_back(x);
                x = par[x];
            }
            return true;
        }
        for(auto i:adj[x]){
            if(!vis[i]){
                q.push(i);
                par[i] = x;
                vis[i] = true;
            }
        }
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
    if(bfs(adj)){
        cout<<ans.size()+1<<endl;
        cout<<1<<" ";
        reverse(ans.begin(),ans.end());
        for(auto i:ans) cout<<i<<" ";
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}