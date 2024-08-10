#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int> v,int mid,int k){
    int c = 1;
    int s = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]>mid) return 0;
        if(s+v[i]>mid){
            s = v[i];
            c++;
        }else{
            s+=v[i];
        }
    }
    return c<=k;
}
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    int s = 0;
    for(auto i:v) s+=i;
    int l = 0;
    int r = s;
    int mid;
    int ans = INT_MAX;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(check(v,mid,k)){
            ans = mid;
            r = mid-1;
        }else l = mid+1;
    }
    cout<<ans;
}