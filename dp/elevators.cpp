#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    int size = (1<<n);
    vector<pair<int,int>> dp(size);
    dp[0] = {1,0};
    for(int mask = 1;mask<size;mask++){
        pair<int,int> best = {INT_MAX,INT_MAX};
        for(int i=0;i<n;i++){
            if((1<<i) & mask){
                auto res = dp[(1<<i)^mask];
                if(res.second+v[i]<=k){
                    res.second+= v[i];
                }else{
                    res.first++;
                    res.second = v[i];
                }
                best = min(best,res);
            }
        }
        dp[mask] = best;
    }
    cout<<dp[size-1].first;
}