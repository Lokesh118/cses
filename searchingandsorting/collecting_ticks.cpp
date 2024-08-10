#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[i] = {x,i};
    }
    auto t = v;
    sort(v.begin(),v.end());
    if(t==v){
        cout<<1;
        return 0;
    }
    int ans = 0;
    int i = 0;
    while(i<n-1){
        while(i<n && v[i].second<v[i+1].second) i++;
        i++;
        ans++;
    }
    if(v[i-1].second > v[i].second) ans++; 
    cout<<ans<<endl;
}