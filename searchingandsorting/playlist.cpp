#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	int i = 0, j = 0, ans = 0, l = 0;
	map<int, int> m;
	while (j < n){
		if (m.find(v[j]) == m.end() || m[v[j]] == 0){
			m[v[j]]++;
			l++;
			ans = max(ans, l);
			j++;
		}else{
			l--;
			m[v[i]]--;
			i++;
		}
	}
	cout << ans;
	return 0;
}