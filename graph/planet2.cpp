#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &par,vector<int> &vis,int src,vector<int> &len){
    if(vis[src]) return;
    vis[src] = 1;
    dfs(par,vis,par[src][0],len);
    len[src] = len[par[src][0]]+1;
}
int lift(vector<vector<int>> &par,int x,int d){
    if(d<=0) return x;
    int i = 0;
    while(d>0){
        if(d&1) x = par[x][i];
        i++;
        d>>=1;
    }
    return x;
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> par(n+1,vector<int>(30,0));
    vector<int> vis(n+1,0);
    vector<int> len(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>par[i][0];
    }
    for(int d=1;d<30;d++){
        for(int i=1;i<=n;i++){
            par[i][d] = par[par[i][d-1]][d-1];
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(par,vis,i,len);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        int eoc = lift(par,a,len[a]);
        if(lift(par,a,len[a]-len[b]) == b){
            cout<<(len[a]-len[b])<<endl;
        }else if(lift(par,eoc,len[eoc]-len[b]) == b){
            cout<<(len[a]+len[eoc]-len[b])<<endl;
        }else cout<<"-1\n";
                
    }
}