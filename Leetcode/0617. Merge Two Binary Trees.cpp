/* Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree. */

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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if(!t1 && !t2)
			return NULL;
		TreeNode *t0 = new TreeNode(0, mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL),  mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL));
		if(t1)
			t0->val += t1->val;
		if(t2)
			t0->val += t2->val;
		return t0;
	}
};