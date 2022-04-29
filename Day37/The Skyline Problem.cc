#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

void display(vector<vector<int>>& arr){
	for(auto i : arr) {
		for(int j : i) cout << j << " ";
		cout << endl;
	}
}

bool sortPointHeight(vector<int>& arr1, vector<int>& arr2) {
	return (arr1[0] == arr2[0]) ? arr1[1] < arr2[1]: arr1[0] < arr2[0];
}

void insertSortPoints(vector<vector<int>>& buildings, vector<vector<int>>& point_height){
	for(vector<int> x_y_h : buildings){
		int x = x_y_h[0], y = x_y_h[1], h = x_y_h[2];
		point_height.push_back({x,-1*h});
		point_height.push_back({y,h});
	}
	sort(point_height.begin(), point_height.end(), sortPointHeight);
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
	int curr_max = 0;
	map<int,int,greater<int>> maxHeight;
	vector<vector<int>> point_height, res;
	
	insertSortPoints(buildings,point_height);
	maxHeight.insert({0,1});
	
	for(auto i : point_height){
		int point = i[0], h = i[1];
		if(h < 0) maxHeight[abs(h)] += 1;	
		else{
			maxHeight[h] -= 1;
			if(maxHeight[h] == 0) maxHeight.erase(h);
		}
		
		auto it = maxHeight.begin();
		int max_now = it->first;
		if(max_now != curr_max){
			res.push_back({point,max_now});
			curr_max = max_now;
		}
	}
	return res;
}

int main() {
	int m,n;
	cin >> m >> n;
	vector<vector<int>> arr(m,vector<int>(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) cin >> arr[i][j];
	
	vector<vector<int>> res = getSkyline(arr);
	display(res);
	
	return 0;
}
