/* You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree. */

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
	string tree2str(TreeNode* root) {
		if(root == NULL)
			return "";
		if(root->left == NULL && root->right == NULL)
			return to_string(root->val);
		string sL = tree2str(root->left);
		sL = "(" + sL + ")";
		string sR = tree2str(root->right);
		if(sR != "")
			sR = "(" + sR + ")";
		return to_string(root->val) + sL + sR;
	}
};
