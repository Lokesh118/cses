#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(vector<vector<int>> &adj,int src,vector<int> &ans){
    while(adj[src].size()){
        int u = adj[src].back();adj[src].pop_back();
        dfs(adj,u,ans);
    }
    ans.push_back(src);
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> in(n+1,0),out(n+1,0);
    int a,b;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;out[a]++;
    }
    int s = -1,e = -1,c=0;
    a=0,b=0;
    for(int i=1;i<=n;i++){
        if(in[i]==out[i]) c++;
        else if(in[i]-out[i]==1){
            e = i;
            b++;
        }else if(in[i]-out[i] == -1){
            s = i;
            a++;
        }
    }
    if(s!=1 || e!=n){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    if(!(c==n-2 && a==1 && b==1)){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    dfs(adj,1,ans);
    reverse(ans.begin(),ans.end());
    if(ans.size()<n){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(auto i:ans) cout<<i<<" ";
}