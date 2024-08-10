#include<bits/stdc++.h>
using namespace std;
#define int long long

int sol(vector<int> &v,int k){
    map<int,int> m;
    int n = v.size();
    int l = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(m.find(v[i])==m.end()){
            m[v[i]] = 0;
        }
        m[v[i]]++;
        while(m.size()>k){
            m[v[l]]--;
            if(m[v[l]] == 0) m.erase(v[l]);
            l++;
        }
        ans += (i-l+1); 
    } 
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    cout<<(sol(v,k));
}