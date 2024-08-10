#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int m;
    cin>>m;
    for(int n = 1;n<=m;n++){
        //if(n==1) cout<<0<<endl;
        int k = n;
        int ans = 0;
        /*int x[8] = {2,1,-2,-1,-2,-1,2,1};
        int y[8] = {1,2,1,2,-1,-2,-1,-2};
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                int count = 0;
                for(int t = 0;t<8;t++){
                    int r = i+x[t];
                    int c = j+y[t];
                    if(r<k && r>=0 && c<k && c>=0) count++;
                }
                ans+= (k*k -(count+1));   
            }
        }
        cout<<(ans)/2<<endl;*/
        ans = ((k*k)*(k*k - 1))/2 - 4*(k-1)*(k-2);
        cout<<ans<<endl;
    }
}