#include "utils.h"

int maxSumIS(int arr[], int n) {  
	int res;
	vector<int> maxSum(n,0);
	
	for(int i=0; i<n; i++) maxSum[i] = arr[i];
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++) {
			if(arr[i] > arr[j] && maxSum[i] < maxSum[j]+arr[i]) maxSum[i] = maxSum[j] + arr[i];
		}
	}

	res = *max_element(maxSum.begin(), maxSum.end());
	return res;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int res = maxSumIS(arr,n);
	display(res);
	
	return 0;
}  
