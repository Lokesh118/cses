#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int t = i;
        while(t){
            int k = t%10;
            dp[i] = min(dp[i],1+dp[i-k]);
            t = t/10;
        }
    }
    cout<<dp[n];
}