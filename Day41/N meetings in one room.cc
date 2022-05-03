#include<bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n) {
	int res, curr;
	vector<vector<int>> end_beg;
	
	res = curr = 0;
	for(int i=0; i<n; i++) end_beg.push_back({end[i],start[i]});
	sort(end_beg.begin(), end_beg.end());
	
	for(int i=0; i<n; i++) {
		if(end_beg[curr][0] < end_beg[i][1]) {
			curr = i;
			res++;
		}
	}
	
	return res;
}
    	
int main() {
	int n;
	cin >> n;
	int start[n], end[n];
	for(int i=0; i<n; i++) cin >> start[i];
	for(int i=0; i<n; i++) cin >> end[i];
	
	int meetings = maxMeetings(start,end,n);
	cout << meetings << endl;
	
	return 0;
}
