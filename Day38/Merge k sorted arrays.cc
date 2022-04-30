#include "utils.h"
typedef pair<int,pair<int,int>> customTuple;  // {val, {curr_row, curr_col}}

class Solution {
public:
	vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
       	vector<int> merged;
       	priority_queue<customTuple, vector<customTuple>, greater<>> minHeap;
       
       	for(int i=0; i<K; i++) minHeap.push({arr[i][0],{i,0}});
       	while(!minHeap.empty()) {
       		auto it = minHeap.top();
       		minHeap.pop();
       		
       		int val = it.first;
       		int row = it.second.first, col = it.second.second;
       		
       		int curr_col_size = arr[row].size();
       		if(col < curr_col_size-1){
       			int next_val = arr[row][col+1];
       			minHeap.push({next_val,{row,col+1}});
       		}
       		merged.push_back(val);
       	}
       	return merged;
    }
};

int main() {
	int k;
	cin >> k;
	vector<vector<int>> arr(k,vector<int>(k));
	insertData(arr);
	
	Solution obj;
	vector<int> merged = obj.mergeKArrays(arr,k);
	for_each(merged.begin(), merged.end(), [](int x){ cout << x << " "; });
	
	return 0;
}
