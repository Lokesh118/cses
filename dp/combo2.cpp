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
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            if(v[i]<=j) dp[j] = (dp[j]+dp[j-v[i]])%mod;
        }
    }
    cout<<dp[x]<<endl;
}