#include "utils.h"

class Solution {
public:
	int totalBSTs(int n, vector<int>& mem){
        if(n == 0) return 1;
        if(n == 1 || n == 2) return n;
        
        if(mem[n] != 0) return mem[n];
        
        int count = 0;
        for(int i=0; i<n; i++){
            count += totalBSTs(i,mem)*totalBSTs(n-i-1,mem);
        }
        mem[n] = count;
        return mem[n];
    }
    
    int numTrees(int n) {
    	vector<int> mem(n+1,0);
	    return totalBSTs(n,mem);
    }	
};

int main() {
	int n;
	cin >> n;
	
	Solution obj;
	int total_BSTs = obj.numTrees(n);
	print(total_BSTs);
	
	return 0;
}
