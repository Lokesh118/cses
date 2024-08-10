#include<bits/stdc++.h>
using namespace std;
#define int long long

unordered_set<string> vis;
vector<int> edges;
void dfs(string s,string &A){
    for(int i=0;i<2;i++){
        string str = s+A[i];
        if(vis.find(str)==vis.end()){
            vis.insert(str);
            dfs(str.substr(1),A);
            edges.push_back(i);
        }
    }
}
signed main(){
    int n;
    cin>>n;
    string A = "01";
    string s(n-1,A[0]);
    dfs(s,A);
    string ans;
    for(int i=0;i<(1<<n);i++){
        cout<<edges[i]<<" ";
        ans+=A[edges[i]];
    }
    cout<<endl;
    ans+=s;
    cout<<ans<<endl;
}