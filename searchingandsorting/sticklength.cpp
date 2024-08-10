#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int mid;
    sort(v.begin(),v.end());
    if(n%2) mid = v[n/2];
    else mid = (v[n/2 - 1]+v[n/2])/2;
    long long int ans = 0;
    for(int i=0;i<n;i++){
        ans+= abs(v[i]-mid);
    }
    cout<<ans;
}