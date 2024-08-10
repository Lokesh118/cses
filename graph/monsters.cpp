#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char>> grid;
int x,y;
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
char dir[4] = {'U','D','R','L'};
int main(){
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++){
        grid[i].resize(m);
    }
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'M') q.push({i,j});
            else if(grid[i][j] == 'A'){
                x = i,y = j;
            }
        }
    }
    

    
}