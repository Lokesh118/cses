#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end());
    int  i = 0;
    int j = n-1;
    while(i<j ){
        if(v[i].first + v[j].first == k){
            cout<<v[i].second<<" "<<v[j].second;
            return 0;
        }else if(v[i].first + v[j].first < k){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<"IMPOSSIBLE";
}