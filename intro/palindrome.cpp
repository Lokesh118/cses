#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<char,int> m;
    for(auto i:s){
        m[i]++;
    }
    int c = 0;
    int n = s.length();
    char x;
    int f=0;
    for(auto i:m){
        if(i.second%2){
            x = i.first;
            f = i.second;
            c++;
        }
        if((c==1 && n%2==0) ||(c>1 && n%2)){
            cout<<"NO SOLUTION"<<endl;
            return 0;
        } 
    }
    string ans;
    for(auto i:m){
        if(i.second%2==0){
            for(int t=0;t<i.second/2;t++){
            ans+= i.first;
            }
        }
    }
    auto t = ans;
    reverse(t.begin(),t.end());
    //cout<<ans<<endl;
    if(f!=0){
        for(int i=0;i<f;i++) ans+= x;
    }
    //cout<<ans<<endl;
    ans+= t;
    cout<<ans<<endl;
}