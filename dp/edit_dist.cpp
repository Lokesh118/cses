#include<bits/stdc++.h>
using namespace std;
//map<pair<string,string>,int> m;
// int edit(string s1,string s2,int i,int j){
//     if(s1 == s2) return 0;
//     if(i==s1.length()-1 || j == s2.length()-1) return (s1.length()-i-1)+(s2.length()-j-1);
//     if(m.find({s1,s2})!=m.end()) return m[{s1,s2}];
//     if(s1[i] == s2[j]) return m[{s1,s2}] = edit(s1,s2,i+1,j+1);
//     else return m[{s1,s2}] = 1 + min({edit(s1,s2,i+1,j), edit(s1,s2,i,j+1),edit(s1,s2,i+1,j+1)});

// }
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int i=0;i<=m;i++) dp[0][i] = i;
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
            }
        }
    }
    cout<<dp[n][m];
}