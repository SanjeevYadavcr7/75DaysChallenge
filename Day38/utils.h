#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void insertData(vector<vector<int>>& arr) {
	int m = arr.size(), n = arr[0].size();
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) cin >> arr[i][j];
}

void display(vector<int> arr){
	for(int i:arr) cout << i << " ";
	cout << endl;	
}

void display(vector<vector<int>> arr){
	for(auto i:arr){
		for(auto j:i) cout << j << " ";
		cout << endl;
	}
}
