#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a,vector<int> &b){
	if(a[2]<b[2]) return 0;
	if(a[2]>b[2]) return 1;
	return a[1]>=b[1];
}
bool cool(vector<int> a,vector<int> b){
	if(a[1]<b[1]) return 1;
	if(a[1]>b[1]) return 0;
	return a[2]<=b[2];
}
vector<int> fun(int n,int k,int w,vector<pair<int,int>> &b){
	int ind = 0;
	vector<int> out(n,-1);
	vector<vector<int>> a;
	for(auto i:b){
		a.push_back({ind,i.first,i.second});
		ind++;
	}
	sort(a.begin(),a.end(),cool);
	ind = 0;
	int ct = 0;
	priority_queue<vector<int>,vector<vector<int>>,comp> pq;
	// priority_queue<vector<int>> pq;
	while(ind<n || !pq.empty()){
		if(ind <n) ct = max(ct,a[ind][1]);
		while(ind<n && a[ind][1]<=ct){
			pq.push(a[ind]);
			ind++;
		}
		if(pq.empty()) ct++;
		else{
			auto now = pq.top();pq.top();
			out[now[0]] = max(0,now[2]*k-(ct-now[1])*w);
			ct+=now[2];
		}
	}
	return out;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,w;
		cin>>n>>k>>w;
		vector<pair<int,int>> A(n);
		for(auto &i:A) cin>>i.first>>i.second;
		auto out = fun(n,k,w,A);
		for(auto i:out) cout<<i<<" ";
		cout<<"\n";
	}
}
