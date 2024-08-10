#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

signed main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    vector<int> dp(x+1,0);
    dp[0] = 0;
    for(int i=0;i<n;i++) if(v[i] <= x) dp[v[i]] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(v[j]<=i) dp[i] = (dp[i]+dp[i-v[j]])%mod;
        }
    }
    cout<<dp[x];
}