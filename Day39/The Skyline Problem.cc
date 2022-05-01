#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>> insertBuildingData(vector<vector<int>>& arr) {
	vector<vector<int>> x_H;
	
	for(auto i : arr){
		x_H.push_back({i[1],i[2]});
		x_H.push_back({i[0],-1*i[2]});	
	}
	
	sort(x_H.begin(), x_H.end(), [](vector<int>& a,vector<int>& b){
		return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
	});
	return x_H;
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
	int curr_max_h;
	int n = buildings.size();
	vector<vector<int>> res;	
	map<int,int,greater<>> heights;
	vector<vector<int>> point_height = insertBuildingData(buildings);
	
	heights.insert({0,1});
	
	for(auto i : point_height) {
		int x = i[0], h = i[1];
		curr_max_h = heights.begin()->first;
		
		if(h < 0) heights[abs(h)] += 1;
		else{
			heights[h] -= 1;
			if(heights[h] == 0) heights.erase(h);
		}
		
		int max_h = heights.begin()->first;
		if(max_h != curr_max_h){
			res.push_back({x,max_h});
			curr_max_h = max_h;
		}
	}
	return res;
}

int main() {	
	int n;
	cin >> n;
	vector<vector<int>> buildings(n,vector<int>(3));	
	for(int i=0; i<n; i++) cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];
	
	vector<vector<int>> res = getSkyline(buildings);
	for(auto i:res){
		for(int j:i) cout << j << " ";
		cout << endl;
	}
	
	return 0;
}
