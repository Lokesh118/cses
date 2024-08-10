#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> pref(n+1,0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pref[i] = pref[i-1]+x;
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(pref[b]-pref[a-1])<<endl;
    }
}