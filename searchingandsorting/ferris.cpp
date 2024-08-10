#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int ans = 0;
    int i = 0;
    int j = n-1;
    while(i<j){
        if(v[i]+v[j]<=k){
            i++;
            j--;
            ans++;
        }else{
            ans++;
            j--;
        }
    }
    if(i==j) ans++;
    cout<<ans<<endl;
}