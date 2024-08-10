#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    multiset<int,greater<int>> s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    while(m--){
        int x;
        cin>>x;
        auto it = s.lower_bound(x);
        if(it == s.end()) cout<<-1<<endl;
        else {
            cout<<*it<<endl;
            s.erase(it);
        }
    }
}