#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> v = {"0","1"};
    int size = v.size();
    for(int i=1;i<n;i++){
        for(int j = size-1;j>=0;j--){
            v.push_back(v[j]);
        }
        for(int j = 0;j<v.size();j++){
            if(j<size) v[j] = "0"+ v[j];
            else v[j] = "1"+ v[j];
        }
        size = v.size();
    }
    for(auto i:v) cout<<i<<endl;
}