#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

signed main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(n==1){
        if(grid[0][0] == '.') cout<<1;
        else cout<<0;
        return 0;
    }
    if(grid[0][0] == '*'){
        cout<<0;
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    if(grid[0][1]!='*') dp[1][2] = 1;
    if(grid[1][0]!='*') dp[2][1] = 1;
    if(dp[1][2]==0 && dp[2][1] == 0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i-1][j-1] == '*') continue;
            dp[i][j] = max(dp[i][j] , (dp[i-1][j]+dp[i][j-1])%mod);
        }
    }
    cout<<dp[n][n];
}