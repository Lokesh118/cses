#include<bits/stdc++.h>
using namespace std;
//#define int long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> pr(n);
    vector<int> pg(n);
    for(auto &i:pr) cin>>i;
    for(auto &i:pg) cin>>i;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(pr[i-1]<=j) dp[i][j] = max(dp[i][j],pg[i-1]+dp[i-1][j-pr[i-1]]);
        }
    }
    cout<<dp[n][x];
}