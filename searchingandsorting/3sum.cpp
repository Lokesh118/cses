#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,t;
    cin>>n>>t;
    if(n<=2){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[i] = {x,i};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;
        while(j<k){
            if(v[i].first+v[j].first+v[k].first == t){
                cout<<v[i].second+1<<" "<<v[j].second+1<<" "<<v[k].second+1;
                return 0;
            }else if(v[i].first+v[j].first+v[k].first < t) j++;
            else k--;
        }
    }
    cout<<"IMPOSSIBLE";
}