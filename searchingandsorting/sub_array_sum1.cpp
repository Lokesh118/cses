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
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    cout<<sol(v,k);
}