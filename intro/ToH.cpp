#include<bits/stdc++.h>
using namespace std;
void ToH(int n,int from_rod,int aux_rod,int to_rod,vector<pair<int,int>> &v){
    if(n==1){
        v.push_back({from_rod,to_rod});
        return;
    }
    ToH(n-1,from_rod,to_rod,aux_rod,v);
    v.push_back({from_rod,to_rod});
    ToH(n-1,aux_rod,from_rod,to_rod,v);
}
int main(){
    vector<pair<int,int>> v;
    int n;
    cin>>n;
    int from_rod = 1;
    int aux_rod = 2;
    int to_rod = 3;
    ToH(n,from_rod,aux_rod,to_rod,v);
    cout<<v.size()<<endl;
    for(auto i:v) cout<<i.first<<" "<<i.second<<endl;
}