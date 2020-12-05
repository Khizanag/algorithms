/* Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself. */

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
	bool isSameTree(TreeNode * root1, TreeNode* root2)
	{
		if(root1 == NULL && root2 == NULL)
			return true;
		if(root1 == NULL || root2 == NULL)
			return false;
		return root1->val == root2->val
			&& isSameTree(root1->left, root2->left)
			&& isSameTree(root1->right, root2->right);
	}
	
	bool isSubtree(TreeNode* tree, TreeNode* subtree) {
		if(tree == NULL && subtree == NULL)
			return true;
		if(tree == NULL || subtree == NULL)
			return false;
		return isSameTree(tree, subtree)
			|| isSubtree(tree->left, subtree)
			|| isSubtree(tree->right, subtree);
	}
};