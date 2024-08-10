#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int timer = 0;
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> q;
    for(int i=0;i<v.size();i++){
        q.push({v[i].first,v[i].second});
    }
    int ans = 0;
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        ans += (t.second - t.first - timer);
        timer += t.first;
    }
    cout<<ans<<endl;
}