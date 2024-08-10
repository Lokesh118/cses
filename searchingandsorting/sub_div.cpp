#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int> v(n);
    unordered_map<int,int> m;
    m[0] = 1;
    int sum = 0;
    for(auto &i:v){
        cin>>i;
        sum += i;
        m[(sum%n+n)%n]++;
    }
    int ans = 0;
    for(auto i:m){
        ans+= ((i.second)*(i.second-1))/2;
    }
    cout<<ans;
}