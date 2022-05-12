int getMinCost(int l, int r, int nums[], vector<vector<int>>& mem) {
    	if(l >= r) return 0;
    	
    	if(mem[l][r] != -1) return mem[l][r];
    	
    	int min_cost = INT_MAX;
    	for(int i=l; i<r; i++) {
    		int cost = nums[l-1] * nums[i] * nums[r] + getMinCost(l,i,nums,mem) + getMinCost(i+1,r,nums,mem);
    		min_cost = min(min_cost,cost);
    	}
    	return mem[l][r] = min_cost;
    }
    
    int matrixMultiplication(int n, int arr[]){
    	vector<vector<int>> mem(n+1,vector<int>(n+1,-1));
    	return getMinCost(1,n-1,arr,mem);
    }
