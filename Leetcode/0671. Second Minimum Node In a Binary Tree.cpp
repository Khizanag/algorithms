/* Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead. */

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
	void fn(TreeNode * root, int &mn, int &mn2, bool &changed1, bool &changed2)
	{
		if(root->left)
			fn(root->left, mn, mn2, changed1, changed2);
		if(root->right)
			fn(root->right, mn, mn2, changed1, changed2);
		if(!changed1 || root->val < mn)
		{
			mn2 = mn;
			mn = root->val;
			changed2 = changed1;
			changed1 = true;
		} 
		else if( (!changed2 || root->val < mn2) && mn != root->val )
		{
			mn2 = root->val;
			changed2 = true;
		}
	}
	
	int findSecondMinimumValue(TreeNode* root) {
		int mn = INT_MAX, mn2 = INT_MAX;
		bool changed1 = false, changed2 = false;
		if(root)
			fn(root, mn, mn2, changed1, changed2);
		if(changed2)
			return mn2;
		else
			return -1;
	}
};