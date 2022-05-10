#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> arr) {
	for(auto i : arr) {
		for(int j : i) cout << j << " ";
		cout << endl;
	}
}


vector<vector<int>> res;
vector<int> temp;
void getCombination(vector<int>& nums, int tar, int idx) {
        if(tar == 0) {
            res.push_back(temp);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++) {
        	if(i>idx && nums[i] == nums[i-1]) continue;
			
			if(nums[i] <= tar) {
				temp.push_back(nums[i]);
		        getCombination(nums,tar-nums[i],i+1);
		        temp.pop_back();
			}
        }
}
    
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        getCombination(candidates,target,0);
        return res;
}

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i=0 ;i<n; i++) cin >> nums[i];
	
	vector<vector<int>> res = combinationSum2(nums,k);
	display(res);
	
	return 0;
}
