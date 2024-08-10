#include<bits/stdc++.h>
using namespace std;
#define int long long
int powr(int x,int y){
    int res =1;
    while(y>0){
        if(y&1) res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}
int findNthDigit(int n) {
    int base = 9;
    long digits = 1;
    while (n - base * digits > 0) {
        n -= base * digits;
        base *= 10;
        digits++;
    }
        
    int index = (n - 1) % digits;
    int offset = (n - 1) / digits;
    long start = pow(10, digits - 1);
    return to_string(start + offset)[index] - '0';
}
signed main(){    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // int c = 1;
        // int t = 9;
        // for (int p = 9;; n -= p, c++, p = 9*powr(10, c-1)*c) {
        //     if (n - p <= 0) break;
        // }
        // n--;
        // int x = n/c;
        // int y = n%c;
        // int temp = powr(10,c-1)+x;
        // string s = to_string(temp);
        // cout<<s[y]<<endl;
        cout<<findNthDigit(n)<<" ";
    }
    
}
