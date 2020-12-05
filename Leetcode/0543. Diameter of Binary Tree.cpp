/* Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root. */

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
	int recLenOfBinaryTree(TreeNode * root)
	{
		if(root == NULL)
			return -1;
		return max(recLenOfBinaryTree(root->left), recLenOfBinaryTree(root->right)) + 1;
	}
	
	int diameterOfBinaryTree(TreeNode* root) 
	{
		if(root == NULL)
			return 0;
		int leftRecLen = recLenOfBinaryTree(root->left);
		int rightRecLen = recLenOfBinaryTree(root->right);
		int thisRes = leftRecLen + rightRecLen + 2;
		int childRes = max(diameterOfBinaryTree(root->left),
						  diameterOfBinaryTree(root->right));
		return max(thisRes, childRes);
	}
};