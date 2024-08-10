#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        long long ans;
        if(a>b){
            if(a%2==0) {
                ans = a * a - b + 1;
                cout<<ans<<endl;
            }
            else{
                ans = (a-1) * (a-1) + b;
                cout<<ans<<endl;
            }
        }else{
            if(b%2 == 0) {
                ans = (b-1) * (b-1) + a;
                cout<<ans<<endl;
            }
            else{
                ans = b * b - a + 1;
                cout<<ans<<endl;
            }
        }
    }
}