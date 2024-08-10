#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";
vector<vector<int>> dp;
vector<vector<int>> adj;
int sol(int src,int f){
    if(dp[src][f]) return dp[src][f];
     
}
signed main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    dp.assign(n+1,vector<int>(2,0));
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

}