#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(v[j]<=i) dp[i] = min(dp[i],1+dp[i-v[j]]);
        }
    }
    if(dp[x] == INT_MAX){
        cout<<-1;
        return 0;
    }
    cout<<dp[x];
}