#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

signed main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    dp[0][0] = 1;
    dp[1][1] = 0;
    
}