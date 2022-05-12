#include "utils.h"

// TC: O(N*W) | SC: O(N*W)

int knapSack(int W, int wt[], int val[], int n) { 
	
	vector<vector<int>> dp(n+1,vector<int>(W+1,0));
	
	for(int item=1; item<=n; item++) {
		int curr_item = item-1;
		for(int capacity=1; capacity<=W; capacity++) {
			if(wt[curr_item] <= capacity) {
				dp[item][capacity] = max(dp[curr_item][capacity], val[curr_item] + dp[curr_item][capacity - wt[curr_item]]);
			} 
			else dp[item][capacity] = dp[curr_item][capacity];
		}	
	}
	display(dp);
	return dp[n][W];
}

int main() {	
	int n,w;
	cin >> n >> w;
	int wt[n], val[n];
	for(int i=0; i<n; i++) cin >> wt[i];
	for(int i=0; i<n; i++) cin >> val[i];
	
	int max_val = knapSack(w,wt,val,n);
	display(max_val);	
	
	return 0;
}
