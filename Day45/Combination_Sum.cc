#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> arr) {
	for(auto i : arr) {
		for(int j : i) cout << j << " ";
		cout << endl;
	}
}
vector<vector<int>> res;

void checkCombinationSum(int idx, int curr_sum, int tar, vector<int> nums, vector<int> temp) {
	if(curr_sum > tar) return;
	if(curr_sum == tar) {
		res.push_back(temp);
		return;
	}
	
	for(int i=idx; i<nums.size(); i++) {
		temp.push_back(nums[i]);
		checkCombinationSum(i,curr_sum + nums[i], tar, nums, temp);
		temp.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<int> temp;
	checkCombinationSum(0,0,target,candidates,temp);
	return res;
}

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i=0 ;i<n; i++) cin >> nums[i];
	
	vector<vector<int>> res = combinationSum(nums,k);
	display(res);
	
	return 0;
}
