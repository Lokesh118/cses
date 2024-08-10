#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxi = 1e16;
signed main(){
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>> t;
    vector<int> par(n+1,0);
    vector<int> dist(n+1,maxi);
    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        t.push_back({u,v,w});
    }
    dist[1] = 0;
    int f = 0;
    for(int i=0;i<n;i++){
        f = 0;
        for(auto x:t){
            tie(u,v,w) = x;
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                par[v] = u;
                f = v;
            }
        }
    }
    if(f==0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    vector<int> cycle;
    for(int i=0;i<n;i++) f = par[f];
    for(int x = f;;x = par[x]){
        cycle.push_back(x);
        if(x==f && cycle.size()>1) break;
    }
    reverse(cycle.begin(),cycle.end());
    for(auto i:cycle) cout<<i<<" ";

}