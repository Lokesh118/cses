#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ispos(int x,vector<int> v,int t){
    int ans = 0;
    for(int i =0;i<v.size();i++){
        ans += (x/v[i]);
        if(ans>=t) return true;
    }
    return ans>=t;
}
int bs(vector<int> v,int t){
    int low = 0;
    int maxi = *max_element(v.begin(),v.end());
    int high = maxi*t+1;
    int ans = LONG_LONG_MAX;
    int mid;
    while(low<=high){
        mid = low + (high - low)/2;
        if(ispos(mid,v,t)){
            ans = mid;
            high = mid-1;
        }else{
            
            low = mid+1;
        }
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<bs(v,t);
}