#include<bits/stdc++.h>
using namespace std;
#define int long long
struct job{
    int start,end,money;
};
bool comp(job a,job b){
    return a.end<b.end;
}
int search(int i,vector<job> &v){
    int l = 0;
    int r = i-1;
    int mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(v[mid].end < v[i].start && v[mid+1].end>=v[i].start) return mid;
        else if(v[mid].end < v[i].start && v[mid+1].end < v[i].start ) l = mid+1;
        else r = mid-1;
    }
    return -1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<job> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].start>>v[i].end>>v[i].money;
    }
    sort(v.begin(),v.end(),comp);
    vector<int> dp(n,0);
    dp[0] = v[0].money;
    for(int i=1;i<n;i++){
        int idx = search(i,v);
        dp[i] = v[i].money;
        if(idx!=-1) dp[i] += dp[idx];
        dp[i] = max(dp[i-1],dp[i]);
    }
    cout<<dp[n-1];
}