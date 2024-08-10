#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({{x,0},i});
        v.push_back({{y,1},i});
    }
    sort(v.begin(),v.end());
    int c = 0;
    vector<int> ans(n);
    vector<int> cur;
    for(auto i:v){
        if(i.first.second == 0){
            c++;
            if(cur.empty()){
                ans[i.second] = c;
            }else{
                ans[i.second] = cur.back();
                cur.pop_back();
            }
        }else{
            c--;
            cur.push_back(ans[i.second]);
        }
    }
    cout<<*max_element(ans.begin(),ans.end())<<endl;
    for(auto i:ans) cout<<i<<" ";
    return 0;
}