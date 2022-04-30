#include "utils.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> minHeap;
            
        for(int& i : nums){
                minHeap.push(i);
        	if(minHeap.size() > k) minHeap.pop();
        }
    	return minHeap.top();
    }
};

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int num = findKthLargest(arr,k);
	cout << num << endl;
	
	return 0;
}
