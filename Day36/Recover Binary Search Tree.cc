#include "utils.h"

class Solution {
public: 
	TreeNode* last_node;
	TreeNode *invalid_node1, *invalid_node2;
	
	void fixBST(TreeNode* node){
		if(!node) return;
		
		fixBST(node->left);
		if(last_node && last_node->val > node->val){
			if(!invalid_node1) invalid_node1 = last_node;
			invalid_node2 = node;
		}
		last_node = node;
		fixBST(node->right);
	}
	
	void recoverTree(TreeNode* root) {
    	last_node = invalid_node1 = invalid_node2 = NULL;
    	fixBST(root);
    	swap(invalid_node1->val,invalid_node2->val);
    }
};

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
	
	Solution obj;
	obj.fixBST(root);
	
	Display(root);
	
	return 0;
}
