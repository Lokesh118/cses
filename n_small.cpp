#include<bits/stdc++.h>
using namespace std;
#define int long long 
void fun(vector<int> v){
    int n = v.size();
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && v[s.top()]>=v[i]) s.pop();
        if(!s.empty()) cout<<s.top()+1<<" ";
        if(s.empty()) cout<<0<<" ";
        s.push(i);
    }
}
signed main(){
    int n;cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    fun(v);
    return 0;
}