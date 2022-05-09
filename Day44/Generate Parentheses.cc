#include<bits/stdc++.h>
using namespace std;
vector<string> res;

void generator(int o, int c, string str, int n) {
	if(o < c || o > n) return;
	
	if(o == c && o == n) {
		res.push_back(str);
		return;
	}
	
	generator(o+1,c,str+"(",n);
	generator(o,c+1,str+")",n);
} 

vector<string> generateParenthesis(int n) {
	int open = 1, close = 0;
	string str = "(";	
	generator(open,close,str,n);	       
	return res;
}

int main() {
	int n;
	cin >> n;

	vector<string> res = generateParenthesis(n);
	for_each(res.begin(), res.end(), [](string str){cout << str << " ";});
	cout << endl;

	return 0;
}
