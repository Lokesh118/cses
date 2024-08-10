#include<bits/stdc++.h>
using namespace std;
bool comp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b){
    if(a.first.first == b.first.first) return a.first.second>b.first.second;
    return a.first.first<b.first.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    for(int i = 0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({{x,y},i});
    }
    sort(v.begin(),v.end(),comp);
    vector<bool> contains(n,false);
    vector<bool> contained(n,false);
    int max_rb = 0;
    int min_rb = INT_MAX;
    for(int i=0;i<n;i++){
        if(v[i].first.second<=max_rb) contained[v[i].second] = true;
        max_rb = max(max_rb,v[i].first.second);
    }
    for(int i=n-1;i>=0;i--){
        if(v[i].first.second>=min_rb) contains[v[i].second] = true;
        min_rb = min(min_rb,v[i].first.second);
    }
    for(auto i:contains) cout<<i<<" ";
    cout<<endl;
    for(auto i:contained) cout<<i<<" ";
}