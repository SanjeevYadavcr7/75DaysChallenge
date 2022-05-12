#include "utils.h"

// Tabulation | TC: O(N*M) | SC: O(N*M)

int minDistance(string word1, string word2) {
	int n = word1.size();
	int m = word2.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	
	for(int i=0; i<=n; i++) dp[i][0] = i;
	for(int j=0; j<=n; j++) dp[0][j] = j;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
		}
	}
	return dp[n][m];
}


/* 
------------------------------------------------------------------------------------------------------------------

Memoization | TC: O(N*M) | SC: O(N*M) + O(N+M)

int f(int i, int j, string word1, string word2, vector<vector<int>>& mem) {
	if(i == 0) return j;
	if(j == 0) return i;
	
	if(mem[i][j] != -1) return mem[i][j];
	
	if(word1[i-1] == word2[j-1]) return mem[i][j] = f(i-1,j-1,word1,word2,mem);
	return mem[i][j] = 1 + min(f(i,j-1,word1,word2,mem), min(f(i-1,j,word1,word2,mem), f(i-1,j-1,word1,word2,mem)));
} 

int minDistance(string word1, string word2) {
	int n = word1.size();
	int m = word2.size();
	vector<vector<int>> mem(n+1,vector<int>(m+1,-1));
	return f(n,m,word1,word2,mem);
}

--------------------------------------------------------------------------------------------------------------------


Recursive appraoch | TC: O(3^(n+m)) | SC: O(n+m)

int f(int i, int j, string word1, string word2) {
	if(i<0) return j+1;
	if(j<0) return i+1;
	
	if(word1[i] == word2[j]) return f(i-1,j-1,word1,word2);
	return 1 + min(f(i,j-1,word1,word2), min(f(i-1,j,word1,word2),f(i-1,j-1,word1,word2)));
}

int minDistance(string word1, string word2) {
	int n = word1.size();
	int m = word2.size();
	return f(n-1,m-1,word1,word2);
}
*/

int main() {
	string word1, word2;
	cin >> word1 >> word2;
	
	int minDis = minDistance(word1, word2);
	cout << minDis << endl;

	return 0;
}
