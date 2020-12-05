/* Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if there the node does not have a right child. */

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
	pair<int, int> fn(TreeNode * root) // tilt, sum
	{
		if(root == NULL)
			return {0, 0};
		auto rL = fn(root->left);
		auto rR = fn(root->right);
		return { rL.first + rR.first + abs(rL.second - rR.second),
				 rL.second + rR.second + root->val };
	}
	
	int findTilt(TreeNode* root) {
		return fn(root).first;
	}
};