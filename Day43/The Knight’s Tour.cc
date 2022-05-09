#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> moves = {{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1}};

void displayBoard(vector<vector<int>> chess){
	int n = chess.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<chess[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

bool isSafe(int row, int col, vector<vector<int>>& arr) {
	if(row<0 || row>=arr.size() || col<0 || col>=arr.size() || arr[row][col] != -1) return false;
	return true;
}

bool knightTravel(int row, int col, int cnt, vector<vector<int>>& path) {
	if(cnt == path.size()*path.size()) return true;
	
	for(auto move : moves) {
		int next_row = row + move[0];
		int next_col = col + move[1];
		if(isSafe(next_row, next_col, path)) {
			path[next_row][next_col] = cnt;
			if(knightTravel(next_row, next_col, cnt+1, path)) return true;
			else path[next_row][next_col] = -1;
		}
	}
	return false;
} 

void getKnightPath(int n) {
	vector<vector<int>> path(n,vector<int>(n,-1));
	path[0][0] = 0;
	if(knightTravel(0,0,1,path)) displayBoard(path);
	else cout << "Can't travel all cells\n";
}

int main() {
	int n;
	cin >> n;
	getKnightPath(n);
	
	return 0;
}
