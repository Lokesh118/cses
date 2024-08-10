#include<bits/stdc++.h>
using namespace std;
pair<int,int> search(vector<int> &x,int a,int b){
    int j,k;
    for(int i=0;i<x.size();i++){
        if(x[i] == a) j = i;
        else if(x[i] == b) k = i;
    }
    return {j,k};
}
void solve(vector<int> &x){
    vector<pair<int,int>> v;
    for(int i=0;i<x.size();i++){
        v.push_back({x[i],i});
    }
    int n = v.size();
    auto t = v;
    sort(v.begin(),v.end());
    if(t==v){
        cout<<1;
        return;
    }
    int ans = 1;
    int i = 0;
    while(i<n-1){
        if(v[i].second<v[i+1].second){
            i++;
        }else{
            ans++;
            i++;
        }
    }
    if(v[i-1].second > v[i].second) ans++; 
    cout<<ans<<endl;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> ind(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        ind[v[i]] = i;
    }
    while(k--){
        int x,y;
        cin>>x>>y;
        swap(v[ind[x]],v[ind[y]]);
        solve(v);
    }
}
