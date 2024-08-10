#include<bits/stdc++.h>
using namespace std;
stack<int> topo;
void dfs(vector<vector<int>> &adj,vector<int> &vis,int src){
    vis[src] = 1;
    for(auto x:adj[src]){
        if(!vis[x]) dfs(adj,vis,x);
    }
    topo.push(src);
}
void dfs(vector<vector<int>> &adj,vector<int> &vis,int src,int k,vector<int> &kgdm){
    vis[src]  = 1;
    kgdm[src] = k;
    for(auto x:adj[src]){
        if(!vis[x]) dfs(adj,vis,x,k,kgdm);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    char x,y;
    int a,b;
    vector<vector<int>> adj(2*m+1),adj2(2*m+1);
    while(n--){
        cin>>x>>a>>y>>b;
        if(x == '-') a = 2*m-a+1;
        if(y ==  '-') b = 2*m-b+1;
        adj[2*m-a+1].push_back(b),adj[2*m-b+1].push_back(a);
        adj2[a].push_back(2*m-b+1),adj2[b].push_back(2*m-a+1);
    }
    vector<int> vis(2*m+1,0);
    for(int i = 1;i<=2*m;i++){
        if(!vis[i]) dfs(adj,vis,i);
    }
    for(int i=1;i<=2*m;i++) vis[i] = 0;
    int k = 0;
    vector<int> kgdm(2*m+2);
    while(!topo.empty()){
        int x = topo.top();topo.pop();
        if(!vis[x]){
            k++;
            dfs(adj2,vis,x,k,kgdm);
        }
    }
    vector<int> sol(m+1,0);
    for(int i=1;i<=m;i++){
        if(kgdm[i] == kgdm[2*m-i+1]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        sol[i] = (kgdm[i]>kgdm[2*m-i+1]);
    }
    for(int i=1;i<=m;i++){
        cout<<(sol[i]?'+':'-')<<" ";
    }
}
    