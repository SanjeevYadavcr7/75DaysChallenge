#include "utils.h"

vector<vector<int>> paths;

bool isValidCell(int r, int c, vector<vector<int>>& chess) {
	int i,j;
	int n = chess.size();
	
	for(int x=0; x<n; x++) {
		if(chess[r][x] == 1) return false;
		if(chess[x][c] == 1) return false;
	}
	
	i = r, j = c;
	while(i<n && j<n) if(chess[i++][j++] == 1) return false;
	
	i = r, j = c;
	while(i>=0 && j>=0) if(chess[i--][j--] == 1) return false;
	
	i = r, j = c;
	while(i>=0 && j<n) if(chess[i--][j++] == 1) return false;
	
	i = r, j = c;
	while(i<n && j>=0) if(chess[i++][j--] == 1) return false;
	
	return true;
}

void visitChess(int row, vector<vector<int>>& chess, vector<int> path) {
	if(row == chess.size()) {
		paths.push_back(path);
		return;
	}
	
	for(int col=0; col<chess.size(); col++) {
		if(isValidCell(row,col,chess)) {
			chess[row][col] = 1;
			path.push_back(col+1);
			visitChess(row+1,chess,path);
			path.pop_back();
			chess[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueen(int n) {
	vector<int> path;
	vector<vector<int>> chess(n,vector<int>(n));	
	visitChess(0,chess,path);
	return paths;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> paths = nQueen(n);
	display(paths);

	return 0;
}
