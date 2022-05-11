#include "utils.h"

vector<string> getCodes(int n) {
	if(n == 1) return {"0","1"};
	
	vector<string> res;
	
	vector<string> codes = getCodes(n-1);
	int len = codes.size();
	for(int i=0; i<len; i++) res.push_back("0"+codes[i]);
	for(int i=len-1; i>=0; i--) res.push_back("1"+codes[i]);
	return res;
}

vector<int> grayCode(int n) {
	vector<int> ans;
	vector<string> codes = getCodes(n);		

	for(string code : codes) ans.push_back(stoi(code,0,2));
	
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> code = grayCode(n);
	display(code);
	
	return 0;
}
