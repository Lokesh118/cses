
#include<bits/stdc++.h>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> par(n+1,vector<int>(30));
    for(int i=1;i<=n;i++){
        cin>>par[i][0];
    }
    for(int d = 1;d<30;d++){
        for(int i=1;i<=n;i++){
            par[i][d] = par[par[i][d-1]][d-1];
        }
    }
    int a,d;
    while(q--){
        cin>>a>>d;
        int y = 0;
        while(d>0){
            if(d&1) a = par[a][y];
            y++;d>>=1;
        }
        cout<<a<<'\n';
    }
}