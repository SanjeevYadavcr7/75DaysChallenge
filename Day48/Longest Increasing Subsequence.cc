#include "utils.h"

/*
	*(nums[i] > nums[j] && dp[i] < dp[j]+1)  // condition for Inc. SubSeq
	
                         i
	arr[] = [0, 1, 0, 2, 3]
	                     j
	
	
	                     i
	dp[]  = [1, 2, 1, 3, 4] 
                         j 

*/

int lengthOfLIS(vector<int>& nums) {
	int len = 0;
	int n = nums.size();
	vector<int> LIS_till_now(n,1);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(nums[i] > nums[j] && LIS_till_now[i] < LIS_till_now[j]+1) LIS_till_now[i] = LIS_till_now[j]+1;
		}
		len = max(len,LIS_till_now[i]);
	}
	return len;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	int res = lengthOfLIS(nums);
	display(res);
	
	return 0;
}
