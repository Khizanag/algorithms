/* Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
	int getLeftMaxDiff(TreeNode* node){
		if(node == NULL || node->left == NULL) return INT_MAX;
		
		TreeNode* starting = node;
		node = node->left;
		while(node->right != NULL) node = node->right;
		
		return starting->val - node->val;
	}
	
	int getRightMinDiff(TreeNode* node){
		if(node == NULL || node->right == NULL) return INT_MAX;
		
		TreeNode* starting = node;
		node = node->right;
		while(node->left != NULL) node = node->left;
		
		return node->val - starting->val;
	}
	
	int getDiff(TreeNode* node){
		if(node == NULL) return INT_MAX;
		return min(getLeftMaxDiff(node), getRightMinDiff(node));
	}
	
	int getMinimumDifference(TreeNode* root) {
		if(root == NULL) return INT_MAX; // base case
		
		return min(getDiff(root), min(getMinimumDifference(root->left), getMinimumDifference(root->right)));
	}
};