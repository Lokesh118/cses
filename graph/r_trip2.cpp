#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> cycle;
bool iscyclic(vector<vector<int>> &adj,vector<int> &vis,vector<int> &stack,int src){
    vis[src] = 1;
    stack[src] = 1;
    for(auto x:adj[src]){
        cycle.push_back(x);
        if(!vis[x] && iscyclic(adj,vis,stack,x)) return true;
        else if(stack[x]) return true;
        cycle.pop_back();
    }
    stack[src] = 0;
    return false;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int a,b;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> vis(n+1,0);
    vector<int> stack(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cycle.push_back(i);
            if(iscyclic(adj,vis,stack,i)){
                int i = 0;
                while(cycle[i]!=cycle.back()){
                    i++;
                }
                cout<<cycle.size()-i<<endl;
                for(;i<cycle.size();i++){
                    cout<<cycle[i]<<" ";
                }
                return 0;
            }
            cycle.pop_back();
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}