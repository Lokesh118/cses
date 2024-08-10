#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int sol(vector<int> &dp,int x){
    if(x<=0) return 0;
    if(dp[x]!=-1) return dp[x];
    if(x<=2) return dp[x] = x;
    dp[x] = x<=6;
    for(int i=1;i<=6;i++){
        dp[x] = (dp[x]+sol(dp,x-i))%mod;
    }
    return dp[x];
}
signed main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<sol(dp,n);
}