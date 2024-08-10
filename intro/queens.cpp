#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
bool isvalid(vector<vector<char>> &m,int r,int c){
    for(int i=r;i>=0;i--){
        if(m[i][c] == '*') return false;
    }
    for(int i=r,j=c;i>=0 && j>=0;i--,j--){
        if(m[i][j] == '*') return false;
    }
    for(int i=r,j=c;i<8 && j>=0;i++,j--){
        if(m[i][j] == '*') return false;
    }
    return true;
}
void back(vector<vector<char>> &m,int r){
    if(r == 8){
        ans++;
        //cout<<ans;
        return;
    }
    for(int i=0;i<8;i++){
        if(isvalid(m,r,i)){
            m[r][i] = '*';
            back(m,r+1);
            m[r][i] = '.';
        }
    }
}
int main(){
    vector<vector<char>> m(8,vector<char>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>m[i][j];
        }
    }
    //int ans = 0;
    back(m,0);
    cout<<ans;
}