#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<int> pref(n+1,0),suf(n+1,0);
    pref[1] = v[1];
    suf[n] = v[n];
    for(int i=2;i<=n;i++){
        pref[i] = min(pref[i-1],v[i]);
        suf[n-i+1] = min(suf[n-i+2],v[n-i+1]);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<v[a]<<endl;
            continue;
        }
        cout<<max(pref[b],suf[a])<<endl;
    }
}