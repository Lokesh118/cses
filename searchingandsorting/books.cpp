#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int mx = INT_MIN;
    int s = 0;
    while(n--){
        int x;
        cin>>x;
        mx = max(mx,x);
        s+=x;
    }
    cout<<max(2*mx,s)<<endl;
    // vector<int> v(n);
    // for(auto &i:v) cin>>i;
    // sort(v.begin(),v.end());
    // int i = 0;
    // int j = n-1;
    // int ans = 0;
    // int extra = 0;
    // while(i<j){
    //     int t = 0;
    //     while(t+v[i]<=v[j]){
    //         t+= v[i];
    //         i++;
    //     }
    //     extra += v[j] - v[i]; 
    //     ans+= v[j--];
    // }
    // ans*=2;
    // cout<<ans<<endl;
}