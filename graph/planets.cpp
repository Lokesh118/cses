#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &par,int src,vector<int> &vis,vector<int> &len){
    if(vis[src]) return;
    vis[src] = 1;
    dfs(par,par[src][0],vis,len);
    len[src] = len[par[src][0]]+1;
}
int lift(vector<vector<int>> &par,int x,int d){
    if(d<=0) return x;
    int i = 0;
    while(d){
        if(d&1) x = par[x][i];
        i++;d>>=1;
    }
    return x;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> par(n+1,vector<int>(30));
    for(int i=1;i<=n;i++){
        cin>>par[i][0];
    }
    for(int d = 1;d<30;d++){
        for(int i =1;i<=n;i++){
            par[i][d] = par[par[i][d-1]][d-1];
        }
    }
    vector<int> vis(n+1,0);
    vector<int> len(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(par,i,vis,len);
    }
    for(int i=1;i<=n;i++){
        int eoc = lift(par,i,len[i]);
        cout<<len[eoc]<<" ";
    }
}