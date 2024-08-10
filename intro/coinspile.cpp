#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        if(l==0 || r == 0){
            if(l==0 && r==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        else if(l > 2*r || r>2*l){
            cout<<"NO"<<endl;
            continue;
        }
        int x = 2*l - r;
        int y = 2*r - l;
        if(x%3 == 0 && y%3 == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}