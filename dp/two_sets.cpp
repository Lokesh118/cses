#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
signed main(){
    int n;
    cin>>n;
    int sum = (n*(n+1))/2;
    if(sum%2){
        cout<<0;
        return 0;
    }
    vector<int> v;
    for(int i=1;i<n;i++) v.push_back(i);
    sum = sum/2;
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=v[i-1]) dp[i][j]+=dp[i-1][j-v[i-1]]%=mod;
        }
    }
    cout<<(dp[n-1][sum])%mod;
}