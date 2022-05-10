#include "utils.h"
vector<vector<int>> sets;

void generateSets(int i, vector<int> temp, vector<int> nums) {
	if(i == nums.size()) {
		sets.push_back(temp);
		return;
	} 
	
	generateSets(i+1,temp,nums);
	temp.push_back(nums[i]);
	generateSets(i+1,temp,nums);
	temp.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<int> temp;
	generateSets(0,temp,nums);
	return sets;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	vector<vector<int>> res = subsets(nums);
	display(res);

	return 0;
}
