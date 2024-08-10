#include<bits/stdc++.h>
using namespace std;
#define int long long
int sol(vector<int> v,int k){
    int sum = 0;
    int l = 0;
    int ans = 0;
    for(int i=0;i<(int)v.size();i++){
        sum += v[i];
        while(sum>k) sum-=v[l++];
        if(sum == k) ans++;
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    bool neg = false;
    for(auto &i:v){
        cin>>i;
        if(i<=0) neg = true;
    }
    if(neg == false){
        cout<<sol(v,k);
        return 0;
    }
    map<int,int> m;
    m[0] = 1;
    int sum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        sum+= v[i];
        ans+= m[sum-k];
        m[sum]++;
    }
    cout<<ans;
}