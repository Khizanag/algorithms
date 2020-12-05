/* Find the sum of all left leaves in a given binary tree. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int fn(TreeNode * root, bool isLeft)
	{
		if(root == NULL)
			return 0;
		if(root->left == NULL && root->right == NULL && isLeft)
			return root->val;
		return fn(root->left, true) + fn(root->right, false);
	}
	
	int sumOfLeftLeaves(TreeNode* root) {
		return fn(root, false);
	}
};