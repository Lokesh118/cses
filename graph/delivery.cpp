#include<bits/stdc++.h>
using namespace std;
vector<int> v;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()%2){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    stack<int> st;
    st.push(1);
    vector<int> ans;
    vector<int> vis(m,0);  
    while(!st.empty()){
        int v = st.top(),f=0;
        while(!adj[v].empty()){
            auto x = adj[v].back();
            adj[v].pop_back();
            if(!vis[x.second]){
                vis[x.second] = 1;
                st.push(x.first);
                f = 1;
                break;
            }
        }
        if(!f){
            ans.push_back(v);
            st.pop();
        }
    }
    if(ans.size()!=m+1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(auto i:ans) cout<<i<<" ";
}