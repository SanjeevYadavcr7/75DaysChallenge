#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> arr) {
	for(auto i : arr) {
		for(int j : i) cout << j << " ";
		cout << endl;
	}
}

vector<vector<int>> res;

void getCombination(int idx, int k, int n, vector<int>& temp) {
	if(k == temp.size()) {
		res.push_back(temp);
		return;
	}
	
	for(int i=idx; i<=n; i++) {
		temp.push_back(i);
		getCombination(i+1,k,n,temp);
		temp.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<int> temp;
	getCombination(1,k,n,temp);	
	return res;
}

int main() {
	int n,k;
	cin >> n >> k;
	
	vector<vector<int>> res = combine(n,k);
	display(res);

	return 0;
}
