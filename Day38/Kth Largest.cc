#include "utils.h"

class Solution {
public:
	// Approach: Using quickSelect method
	
	static int getPivot(int l, int r, vector<int>& nums){
		int i = l-1;
		for(int j=l; j<r; j++){
			if(nums[j] <= nums[r]){
				i++;
				swap(nums[i],nums[j]);
			}
		}
		swap(nums[i+1],nums[r]);
		return i+1;
	}

	static int quickSelect(int l, int r, int k, vector<int>& nums) {
		if(l <= r){
			int pivot = getPivot(l,r,nums);
			if(pivot == n-k) return nums[pivot];
			else if(pivot > n-k) return quickSelect(l,pivot-1,k,nums);
			else return quickSelect(pivot+1,r,k,nums);
		}
		return -1;
	}

	static int findKthSmallest(vector<int>& nums, int k) {
		int n = nums.size();
		return quickSelect(0,n-1,k,nums);
	}	
	
	
	/* Approach: Using priority queue
	
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> minHeap;
            
        for(int& i : nums){
                minHeap.push(i);
        	if(minHeap.size() > k) minHeap.pop();
        }
    	return minHeap.top();
    }
    */
};

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int num = Solution::findKthSmallest(arr,k);
	cout << num << endl;
	
	return 0;
}
