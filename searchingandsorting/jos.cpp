#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    bool print = false;
    while(!q.empty()){
        if(print){
            cout<<q.front()<<" ";
            q.pop();
            print  = false;
        }else{
            int x = q.front();
            q.pop();
            q.push(x);
            print  = true;
        }
    }

}