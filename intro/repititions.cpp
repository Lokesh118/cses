#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int ans = INT_MIN;
    int i = 0;
    while(i<n){
        int j = i+1;
        while(j<n && s[i]==s[j]) j++;
        ans = max(ans,j-i);
        i = j;
    }
    cout<<ans;
}