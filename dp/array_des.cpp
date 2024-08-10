#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
// int back(vector<vector<int>> &dp,int i,int val,int &ub,vector<int> &v){
//     if(i+1 < v.size() && v[i+1]>0 && abs(v[i+1]-v[i])>1) return 0;
//     if(i>0 && abs(v[i]-v[i-1])>1) return 0;
//     if(dp[i][val]!=-1) return dp[i][val];
//     if(val>ub) return dp[i][val] = 0;
//     for(int j=i;j<v.size();j++){
//         if(v[i]) dp[i][val] = dp[i-1][val];
//         else dp[i][val] = 1 + back(dp,i+1,val-1,ub,v)%mod + back(dp,i+1,val,ub,v)%mod + back(dp,i+1,val+1,ub,v) % mod;
//     }
//     return 0;
// }
signed main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    //back(dp,0,v[0],m,v);
    if(v[0]) dp[0][v[0]] = 1;
    else{
        for(int i=1;i<=m;i++) dp[0][i] = 1;
    }
    for(int i=1;i<n;i++){
        if(v[i]){
            for(int j=-1;j<2;j++){
                if(v[i]+j>=1 && v[i]+j<=m) dp[i][v[i]] = (dp[i][v[i]]+dp[i-1][v[i]+j])%mod;
            }
        }else{
            for(int k=1;k<=m;k++){
                for(int j=-1;j<2;j++){
                    if(k+j>=1 && k+j<=m) dp[i][k] = (dp[i][k] + dp[i-1][k+j])%mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans = (ans+dp[n-1][i])%mod;
    }
    cout<<ans;
    return 0;
}