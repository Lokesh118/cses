#include<bits/stdc++.h>
using namespace std;
#define int long long

int sol(vector<vector<int>> &dp,int l,int r,vector<int> &v){
    if(l>r){
        return 0;
    }
    if(l==r) return dp[l][r] = v[l];
    if(dp[l][r]!= -1) return dp[l][r];
    int x = v[l] + min(sol(dp,l+2,r,v),sol(dp,l+1,r-1,v));
    int y = v[r]+ min(sol(dp,l+1,r-1,v),sol(dp,l,r-2,v));
    return dp[l][r] = max(x,y);
}
signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<sol(dp,0,n-1,v);
}