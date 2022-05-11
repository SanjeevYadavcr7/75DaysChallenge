#include "utils.h"

/*
	arr[] = { -2, 0, -1 }
	pre[] = { -2, 0, -1 } 
	suf[] = { -2, 0, -1 }
	

*/

int maxProduct(vector<int>& nums) {
	int n = nums.size();
	int max_prod = 0;	
	int pre_prod = 1, suff_prod = 1;
	
	for(int i=0; i<n; i++) {
		pre_prod = (pre_prod == 0 ? 1 : pre_prod) * nums[i];
		suff_prod = (suff_prod == 0 ? 1 : suff_prod) * nums[n-i-1];
		max_prod = max(max_prod,max(pre_prod,suff_prod)); 
	}
	return max_prod;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	int res = maxProduct(nums);
	display(res);
	
	return 0;
}
