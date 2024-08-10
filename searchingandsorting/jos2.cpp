#include<bits/stdc++.h>
using namespace std;
//#define int long long 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    //k = k%n;
    /*queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    int c = 0;
    while(!q.empty()){
        if(c == k){
            cout<<q.front()<<" ";
            q.pop();
            c = 0;
        }else{
            int x = q.front();
            q.pop();
            q.push(x);
            c++;
        }
    }*/
    set<int> s;
    int ind = n%k;
    while(n--){
        

    }
}