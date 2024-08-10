#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int total = n*(n+1)/2;
    if((total%2)) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        total/= 2LL;
        vector<long long int> a,b;
        while(n){
            if(total-n>=0){
                a.push_back(n);
                total-= n;
            }else{
                b.push_back(n);
            }
            n--;
        }
        cout<<a.size()<<endl;
        for(auto i:a) cout<<i<<" ";
        cout<<endl;
        cout<<b.size()<<endl;
        for(auto i:b) cout<<i<<" ";
    }
}