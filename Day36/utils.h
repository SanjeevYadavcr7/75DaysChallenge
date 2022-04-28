#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int _val) {
		val = _val;
		left = right = NULL;
	}
};

template <typename T>
void print(T x){ cout << x << "\n"; }

template <typename T>
void display(vector<T>& arr) {
	for(T& i : arr) cout << i << " ";
	cout << "\n";
}

void display(TreeNode* node){
	if(!node) return;
	
	display(node->left);
	cout << node->val << " ";
	display(node->right);
}



