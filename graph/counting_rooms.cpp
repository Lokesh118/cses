#include<bits/stdc++.h>
using namespace std;
int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};
void dfs(vector<vector<char>> &Map,int i,int j,vector<vector<bool>> &vis){
    vis[i][j] = true;
    for(int k=0;k<4;k++){
        int row = i+x[k];
        int col = j+y[k];
        if(row>=0 && col>=0 && row<Map.size() && col<Map[0].size() && !vis[row][col]){
            dfs(Map,row,col,vis);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> Map(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Map[i][j];
            vis[i][j] = (Map[i][j]=='#');
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                count++;
                dfs(Map,i,j,vis);
            }
        }
    }
    cout<<count;
    return 0;
}