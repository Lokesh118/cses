#include<bits/stdc++.h>
using namespace std;

void sliding_median(vector<int> v,int k){
    int n = v.size();
    if(k == 1){
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        return;
    }
    if(k==2){
        for(int i=1;i<n;i++){
            cout<<min(v[i-1],v[i])<<" ";
        }
        return;
    }
    set<pair<int,int>> ls;
    set<pair<int,int>> rs;
    for(int i=0;i<k;i++){
        ls.insert({v[i],i});
    }
    while(ls.size()>rs.size()+1){
        auto it = ls.rbegin();
        rs.insert(*it);
        ls.erase(ls.find(*it));
    }
    cout<<ls.rbegin()->first<<" ";
    for(int i = 1;i<n-k+1;i++){
        pair<int,int> t = {v[i-1],i-1};
        if(ls.find(t)!=ls.end()) ls.erase(ls.find(t));
        else rs.erase(rs.find(t));
        t = {v[i+k-1],i+k-1};
        if(t.first > ls.rbegin()->first) rs.insert(t);
        else ls.insert(t);
        while(ls.size()<=rs.size()){
            ls.insert(*rs.begin());
            rs.erase(rs.begin());
        }
        while(ls.size()>rs.size()+1){
            auto it = ls.rbegin();
            rs.insert(*it);
            ls.erase(ls.find(*it));
        }
        cout<<ls.rbegin()->first<<" ";
    }
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    sliding_median(v,k);
}