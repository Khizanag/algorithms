/* Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them. */

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
	int univaluePath(TreeNode* root, int value){
		if(root == NULL || value != root->val) return 0;
		
		return (1 + max(univaluePath(root->left, value), univaluePath(root->right, value)));
	}
	
	int longestUnivaluePath(TreeNode* root) {
		if(root == NULL) return 0;
		int result = univaluePath(root->left, root->val) + univaluePath(root->right, root->val);
		int recMax = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
		
		return max(result, recMax);
	}
};