#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long int power(int n){
    if(n==0) return 1;
    if(n==1) return 2;
    long long int k = power(n/2);
    k = k%mod;
    if(n%2) return (2*k*k)%mod;
    else return (k*k)%mod;
}
int main(){
    int n;
    cin>>n;
    cout<<power(n);
    return 0;
}