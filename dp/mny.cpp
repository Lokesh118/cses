#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    int sum = accumulate(v.begin(),v.end(),0);
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    dp[0][0] = 1;
    for(int i=1;i<=sum;i++) dp[0][i] = 0;
    for(int j=1;j<n;j++) dp[j][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(v[i-1]<=j) dp[i][j] = dp[i][j] || dp[i-1][j-v[i-1]];
        }
    }
    set<int> x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(dp[i][j]) x.insert(j);
        }
    }
    cout<<x.size()<<endl;
    for(auto i:x) cout<<i<<" ";
}