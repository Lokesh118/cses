#include<bits/stdc++.h>
using namespace std;
bool comp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b){
    if(a.first.first == b.first.first){
        cout<<a.first.second<<b.first.second;
        return a.first.second>b.first.second;
    } 
    return a.first.first<b.first.first;
}
int solve(vector<int> &v,int k){
    int n = v.size();
    int i = 0;
    int curmin = *min_element(v.begin(),v.begin()+k);
    int ans = curmin;
    int i = 1;
    while(i<n-k+1){
        int j = i+k-1;
        if(curmin == v[i-1]){
            curmin = *min_element(v.begin()+i,v.begin()+i+k);
        }else{
            curmin = min(curmin,v[j]);
        }
        ans = max(ans,curmin);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    for(int i = 0;i<n;i++){
        int x,y;
        cin>>x>>y;
        //cout<<x<<" "<<y<<endl;
        v.push_back({{x,y},i});
    }
    sort(v.begin(),v.end(),comp);
    vector<int> contains(n,0);
    vector<int> contained(n,0);
    set<int> s1;
    set<int> s2;
    for(int i=0;i<n;i++){
        s1.insert(v[i].first.second);
        auto it = s1.upper_bound(v[i].first.second);
        auto it1 = s1.lower_bound(v[i].first.second);
        if(it1 == s1.end())  contained[v[i].second] = s1.size();
        else if(it == s1.end()) continue;
        else contained[v[i].second] = distance(it,it1);
    }
    for(int i=n-1;i>=0;i--){
        s2.insert(v[i].first.second);
        auto it = s2.lower_bound(v[i].first.second);
        if(it == s1.end()) continue;
        else contains[v[i].second] = distance(it,s2.begin());
    }
    for(auto i:contains) cout<<i<<" ";
    cout<<endl;
    for(auto i:contained) cout<<i<<" ";
}