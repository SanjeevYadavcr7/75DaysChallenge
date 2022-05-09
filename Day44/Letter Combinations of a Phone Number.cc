#include<bits/stdc++.h>
using namespace std;

vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void getLetters(int idx, string digits, vector<string>& res) {
	if(idx >= digits.size()) return;
	
	vector<string> temp;
	
	int key = digits[idx]-'0';
	for(string str : res) {
		for(char ch : keys[key]) temp.push_back(str+ch);
	}
	res = temp;
	
	getLetters(idx+1,digits,res);
}

vector<string> letterCombinations(string digits) {
	if(digits.size() == 0 || digits == "") return {};
	vector<string> res = {""};
	getLetters(0,digits,res);
	return res;
}

int main() {
	string str;
	cin >> str;
	
	vector<string> res = letterCombinations(str);
	for_each(res.begin(), res.end(), [](string str){cout << str << " ";});
	cout << endl;

	return 0;
}
