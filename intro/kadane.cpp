#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    long long int sum = 0;
    long long int max_sum = INT_MIN;
    for(int i=0;i<n;i++){
        sum+= v[i];
        max_sum = max(sum,max_sum);
        if(sum<0) sum = 0;
    }
    cout<<max_sum;
}