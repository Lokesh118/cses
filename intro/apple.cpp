#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll ans = 1e18;
    for(int i=0;i<(1<<n);i++){
        ll suma=0,sumb=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) suma+= v[j];
            else sumb+= v[j];
        }
        ans = min(ans,abs(suma-sumb));
    }
    cout<<ans<<endl;
}