#include<queue>
#include<vector>
#include<iostream>
#include <climits>
#include<algorithm>
using namespace std;

// Appraoch: Using Dijkstra Algorithm | TC: O(VlogE + E) | SC: O(E)

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = times.size();
        vector<int> dis(n+1,INT_MAX);
        vector<vector<pair<int,int>>> G(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> Q;
        
        for(int i=0; i<t; i++) G[times[i][0]].push_back({times[i][1], times[i][2]});
        dis[k] = 0;
        Q.push({0,k});
        while(!Q.empty()) {
            auto it = Q.top();
            Q.pop();
            
            int u = it.second;

            for(auto i : G[u]) {
                int v  = i.first;
                int w = i.second;
                if(dis[v] > dis[u]+w){
                    dis[v] = dis[u]+w;
                    Q.push({dis[v],v});
                }
            }
        }
        int delay = 0;
        for(int i=1; i<n+1; i++){
        	delay = max(delay,dis[i]);
        }
        return (delay == INT_MAX) ? -1 : delay;
}

int main() {
	int e;
	int n,k;
	cin >> e;
	vector<vector<int>> times(e,vector<int>(3));
	for(int i=0; i<e; i++)
		for(int j=0; j<3; j++) cin >> times[i][j];
	
	cin >> n >> k;
	
	int delay = networkDelayTime(times,n,k);
	cout << delay << endl;

	return 0;
}
