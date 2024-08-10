#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    int i = 0;
    int ans = 0;
    int cur_end = 0;
    while(i<n){
        if( v[i].second>=cur_end){
            ans++;
            cur_end = v[i].first;
        }
        i++;
    }
    cout<<ans;

}
