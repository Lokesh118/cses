#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(vector<int> v,int k){
    int n = v.size();
    int cost = 0;
    set<int> ls;
    set<int> rs;
    for(int i=0;i<k;i++){
        ls.insert(v[i]);
    }
    while(ls.size()>rs.size()+1){
        auto it = ls.rbegin();
        rs.insert(*it);
        ls.erase(ls.find(*it));
    }
    int m = *ls.rbegin();
    for(auto i:ls) cost+= abs(i-m);
    for(auto i:rs) cost+= abs(i-m);
    cout<<cost<<" ";
    int prev_m = m;
    int prev_cost = cost;
    for(int i=1;i<n-k+1;i++){
        int x = v[i-1];
        auto it = ls.find(x);
        if(it!=ls.end()) ls.erase(it);
        else rs.erase(rs.find(x));
        int y = v[i+k-1];
        if(y > *ls.rbegin()) rs.insert(y);
        else ls.insert(y);
        while(ls.size()<=rs.size()){
            ls.insert(*rs.begin());
            rs.erase(rs.begin());
        }
        while(ls.size()>rs.size()+1){
            auto it = ls.rbegin();
            rs.insert(*it);
            ls.erase(ls.find(*it));
        }
        m = *ls.rbegin();
        cost = prev_cost - (prev_m - x);
        cost += abs(m-prev_m)*(k-2);
        cost += abs(m-y);
        cout<<cost<<" ";
        prev_cost = cost;
        prev_m = m;
    }
}
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    solve(v,k);
}