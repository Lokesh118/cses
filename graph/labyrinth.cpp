#include<bits/stdc++.h>
using namespace std;
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
char d[4] = {'R','L','D','U'};
int startx,starty,endx,endy;
string ans;
bool bfs(vector<vector<char>> &grid,vector<vector<int>> &vis,vector<vector<char>> &dir){
    queue<pair<int,int>> q;
    q.push({startx,starty});
    vis[startx][starty] = true;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int i = t.first;
        int j = t.second;
        if(grid[i][j]=='B'){
            while(1){
                ans.push_back(dir[i][j]);
                if(dir[i][j] == 'U') i++;
                else if(dir[i][j] == 'L') j++;
                else if(dir[i][j] == 'D') i--;
                else if(dir[i][j] == 'R') j--;
                if(i==startx && j==starty) break;
            }
            return true;
        }
        for(int k=0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];
            if(row>=0 && row<(int)grid.size() && col>=0 && col<(int)grid[0].size() && !vis[row][col]){
                dir[row][col] = d[k];
                q.push({row,col});
                vis[row][col] = 1;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<char>> dir(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                startx = i;
                starty = j;
            }else if(grid[i][j]=='B'){
                endx = i;
                endy = j;
            }else{
                vis[i][j] = (grid[i][j] == '#');
            }
        }
    }
    if(bfs(grid,vis,dir)){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }else{
        cout<<"NO";
    }
}