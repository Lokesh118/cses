#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,cur;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>cur;
        auto it = upper_bound(v.begin(),v.end(),cur);
        if(it == v.end()){
            v.push_back(cur);
        }else{
            *it = cur;
        }
    }
    cout<<v.size();
}