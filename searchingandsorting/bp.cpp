
#include <bits/stdc++.h>
#include <string.h>
using namespace std;



bool bpm(vector<vector<int>> bpGraph, int u,bool seen[], int matchR[]){
    int s = bpGraph[0].size();
	for (int v = 0; v < s; v++){
		if (bpGraph[u][v] && !seen[v]){
			seen[v] = true;
			if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
									seen, matchR))
			{
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

int maxBPM(vector<vector<int>> &bpGraph)
{   int s = bpGraph[0].size();
    int n = bpGraph.size();
	int matchR[n];
	memset(matchR, -1, sizeof(matchR));
	int result = 0;
	for (int u = 0; u < n; u++)
	{
		bool seen[s];
		memset(seen, 0, sizeof(seen));
		if (bpm(bpGraph, u, seen, matchR))
			result++;
	}
	return result;
}
int solution(vector<int> A,vector<int> B,int s){
    int n = A.size();
    if(s<n) return 0;
    vector<vector<int>> bpGraph(n,vector<int>(s,0));
    for(int i=0;i<n;i++){
        bpGraph[A[i]][B[i]] = 1;
        bpGraph[B[i]][A[i]] = 1;
    }
    if(maxBPM(bpGraph) < n) return 0;
    return 1;
}

int main()
{
	cout<<solution({1,1,3},{2,2,1},3);
    //cout<<solution({3,2,3,1},{1,3,1,2},3);

	return 0;
}
