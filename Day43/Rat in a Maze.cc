#include<bits/stdc++.h>
using namespace std;

vector<string> paths;
vector<char> dirs = {'L','U','R','D'};
vector<vector<int>> moves = {{0,-1},{-1,0},{0,1},{1,0}};

bool outOfBox(int row, int col, int n) {
	if(row<0 || row>=n || col<0 || col>=n) return true;
	return false;
}

void visitBox(int row, int col, vector<vector<int>>& box, int n, string path) {
	if(outOfBox(row,col,n) || box[row][col] == 0) return;
	
	if(row == n-1 && col == n-1) {
		paths.push_back(path);
		return;
	}
	box[row][col] = 0;
	for(int i=0; i<4; i++) visitBox(row+moves[i][0],col+moves[i][1],box,n,path+dirs[i]);
	box[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
	visitBox(0,0,m,n,"");
	vector<string> no_path = {"-1"};
	return paths.size() ? paths : no_path;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n,vector<int>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) cin >> arr[i][j];
	
	vector<string> path = findPath(arr,n);
	for_each(path.begin(), path.end(), [](string str){cout << str << " ";});
	cout << endl;

	return 0;
}
