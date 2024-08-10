#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
 

// int ans = 0;
// set<int> vis;
// map<set<int>,int> dp;
// int dfs(vector<vector<int>> &adj,int src){
//     if(dp.find(vis)!=dp.end()) return dp[vis];
//     if(src == adj.size()-1){
//         if(vis.size() == adj.size()-1) return dp[vis] = 1;
//         return 0;
//     }
//     vis.insert(src);
//     int t_ans = 0;
//     for(auto x:adj[src]){
//         if(vis.find(x)==vis.end()){
//             vis.insert(x);
//             t_ans += dfs(adj,x);
//             ans+=t_ans;
//             vis.erase(x);
//         }
//     }
//     return dp[vis] = t_ans;
// }
signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    int a,b;
    while(m--){
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
    }
    vector<vector<int>> dp(n,vector<int>((1<<n),0));
    dp[0][1] = 1;
    for(int i=1;i<(1<<n);i++){
        if(i&1 == 0) continue;
        if((i&(1<<(n-1))) && (i!=((1<<n)-1))) continue;
        for(int j = 0;j<n;j++){
            if(i&(1<<j) == 0) continue;
            int prev = i - (1<<j);
            for(auto it:adj[j]){
                if(i && (1<<it)){
                    (dp[j][i]+=dp[it][prev])%=mod;
                }
            }
        }
    }
    cout<<dp[n-1][(1<<n)-1];
}