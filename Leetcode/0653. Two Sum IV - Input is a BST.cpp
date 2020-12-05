/* Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target. */

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
	bool findNumber(TreeNode* firstNode, TreeNode* node, int d){
		if(node == NULL) return false;
		
		if(node->val == d) return (node != firstNode);
		
		if(node->val > d) return findNumber(firstNode, node->left, d);
		else return findNumber(firstNode, node->right, d);
	}
	
	bool findTarget(TreeNode* node, TreeNode* root, int k){
		if(node == NULL) return false;
		
		return findNumber(node, root, k - node->val) 
			|| findTarget(node->left, root, k) 
			|| findTarget(node->right, root, k);
	}

	bool findTarget(TreeNode* root, int k) {
		return findTarget(root, root, k);
	}
};