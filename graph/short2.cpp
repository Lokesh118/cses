#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> v(n+1,vector<int>(n+1,LLONG_MAX));
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a][b] = min(v[a][b],c);
        v[b][a] = min(v[b][a],c);
    }
    for(int i=1;i<=n;i++) v[i][i] = 0;
    auto dist = v;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(dist[i][j] > (dist[i][k]+dist[k][j]) && (dist[i][k]!=LLONG_MAX) && (dist[k][j]!=LLONG_MAX)){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b] == LLONG_MAX) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
    }
}