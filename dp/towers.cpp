#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define mx 1e6+3
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> dp(mx,vector<int>(2,0));
    dp[1][0] = 1;
    dp[1][1] = 1; 
    for(int i=2;i<mx;i++){
        dp[i][0] = (4*dp[i-1][0]%mod + dp[i-1][1])%mod;
        dp[i][1] = (dp[i-1][0]+2*dp[i-1][1]%mod)%mod;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%mod<<endl;
    }
}