#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";

int dfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &cnt,int src){
    vis[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x]){
            cnt[src]+=dfs(adj,vis,cnt,x);
        }
    }
    return cnt[src];
}
signed main(){
    int n;
    cin>>n;
    vector<vector<int>>  v(n+1);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    vector<int> cnt(n+1,1);
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(v,vis,cnt,i);
    }
    for(int i=1;i<n;i++){
        cout<<(--cnt[i])<<" ";
    }
    cout<<(--cnt[n])<<endl;
}