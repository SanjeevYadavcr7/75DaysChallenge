#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> start, vector<int> end, int n) {
       
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
