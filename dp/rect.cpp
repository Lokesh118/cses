#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    vector<vector<int>> dp(505,vector<int>(505,INT_MAX));
    for(int i=0;i<=max(a,b);i++) dp[i][i] = 0;
    for(int i=1;i<=a;i++){
        for(int j=i+1;j<=b;j++){
            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j],1+dp[i][j-k]+dp[i][k]);
            }
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            }
            dp[j][i] = dp[i][j];
        }
    }
    cout<<dp[a][b];
}