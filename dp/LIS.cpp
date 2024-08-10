#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    vector<int> ans;
    for(int i=0;i<n;i++){
        auto it = lower_bound(ans.begin(),ans.end(),v[i]);
        if(it == ans.end()){
            ans.push_back(v[i]);
        }
        else{
            *it = v[i];
        }
    }
    cout<<ans.size();
}