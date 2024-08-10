#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,n;
    cin>>x>>n;
    
    multiset<int> m,s;
    s.insert(0);
    s.insert(x);
    m.insert(x);
    int cur;
    while(n--){
        cin>>cur;
        auto it = s.upper_bound(cur);
        auto itl = it;
        itl--;
        int diff = *it - *itl;
        m.erase(m.find(diff));
        m.insert(*it-cur);
        m.insert(cur-*itl);
        s.insert(cur);
        cout<<*m.rbegin()<<" ";
    }

}