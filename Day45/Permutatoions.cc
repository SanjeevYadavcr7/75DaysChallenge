#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> res;
    void permuteNums(vector<int> nums, unordered_map<int,bool>& used, vector<int> per) {
        if(per.size() == nums.size()) {
            res.push_back(per);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(!used[nums[i]]) {
                used[nums[i]] = true;
                per.push_back(nums[i]);
                permuteNums(nums,used,per);   
                per.pop_back();
                used[nums[i]] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> used;
        vector<int> per;
        permuteNums(nums,used,per);     
        return res;   
    }

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0 ;i<n; i++) cin >> nums[i];
	
	vector<vector<int>> res = permute(nums);
	for(auto i : res) {
		for(int j : i) cout << j << " ";
		cout << endl; 
	}

	return 0;
}
