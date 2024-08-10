#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    long long int c = 0;
    for(int i=0;i<n;i++){
        if(c<v[i]-1){
            break;
        }else c+= v[i];
    }
    cout<<c+1;
}