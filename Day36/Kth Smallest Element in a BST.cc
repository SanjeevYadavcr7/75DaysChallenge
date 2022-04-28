#include "utils.h"

class Solution {
public:
	void getKthSmallest(TreeNode* root, int& k, int& num){
			if(!root || num != -1) return;
			
			getKthSmallest(root->left,k,num);
			k--;
			if(k == 0){
				num = root->val;
				return;
			}
			getKthSmallest(root->right,k,num);
		}
		
	int kthSmallest(TreeNode* root, int k) {
        	if(!root) return -1;
        	
        	int num = -1;
        	getKthSmallest(root,k,num);
    		return num;
    }	
};

int main(){
	int k;
	Solution obj;
	
	cin >> k;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	
	int num = obj.kthSmallest(root,k);
	print(num);

	return 0;
}
