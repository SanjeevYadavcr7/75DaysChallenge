#include<iostream>
#include<vector>
using namespace std;

void heapify(int i, int n, vector<int>& arr) {
	int l = 2*i+1;
	int r = 2*i+2;
	int max_idx = i;
	
	if(l<n && arr[l] > arr[max_idx]) max_idx = l;
	if(r<n && arr[r] > arr[max_idx]) max_idx = r;
	if(max_idx != i){
		swap(arr[max_idx], arr[i]);
		heapify(max_idx,n,arr);
	}
}

void heapSort(vector<int>& arr) {
	int n = arr.size();
	for(int i=n/2-1; i>=0; i--) heapify(i,n,arr);
	
	for(int i=n-1; i>=0; i--){
		swap(arr[i],arr[0]);
		heapify(0,i,arr);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	heapSort(arr);
	for(int& i : arr) cout << i << " ";
	cout << endl;
	
	return 0;
}
