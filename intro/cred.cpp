#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int power(int x,int d){
    if(d==0) return 1;
    if(d==1) return x;
    long long int k = power(x,d/2);
    k = k%mod;
    if(d%2) return (x*k*k)%mod;
    else return (k*k)%mod;
}
int sol(int d){
    long long int ans = 1;
    ans = (ans+(5*power(2,d-1)%mod)%mod)%mod;
    ans = (ans+power(3,d-1)%mod)%mod;
    ans = (ans+power(4,d-1)%mod)%mod;
    ans = (ans+power(5,d-1)%mod)%mod;
    return ans%mod;
}
int main(){
    cout<<sol(1000);
}