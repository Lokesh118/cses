#include<bits/stdc++.h>
using namespace std;
// bool solution(vector<int> A, vector<int> B, int S) {
//     set<pair<int, int>> slots; 
//     int x = A.size();
//     if(x > S) return false; 
//     for(int i=0; i< x;i++){
//         pair<int,int> current = make_pair(A[i], B[i]); 
//         pair<int,int> currRev = make_pair(B[i], A[i]); 
//         if (slots.find(current) == slots.end()) slots.insert(current); 
//         else if (slots.find(currRev) == slots.end()) slots.insert(currRev); 
//         else return false; 
//     }
//     return true; 
// }

int rec(vector<vector<vector<int>>> &dp, vector<int> &v,int i,int x,int y){
    if(dp[i][x][y] !=-1) return dp[i][x][y];
    if(x<v[i] && y<v[i]) return dp[i][x][y] = 0;
    if(x<v[i]){
        return dp[i][x][y] =  1+rec(dp,v,i+1,x,y-v[i]);
    }else if(y<v[i]){
        return dp[i][x][y] = 1+rec(dp,v,i+1,x-v[i],y);
    }
    return dp[i][x][y] = 1+max(rec(dp,v,i+1,x,y-v[i]),rec(dp,v,i+1,x-v[i],y));
    
}
int ans(vector<int> v,int x,int y){
    sort(v.begin(),v.end());
    //reverse(v.begin(),v.end());
    int i = 0;
    int ans = 0;
    int n = v.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(x+1,vector<int>(y+1,-1)));
    return rec(dp,v,0,x,y);
}
int main(){
    //cout<<solution({1,1,3},{2,2,1},3)<<endl;;
    cout<<ans({6,5,5,4,3},8,9);
}