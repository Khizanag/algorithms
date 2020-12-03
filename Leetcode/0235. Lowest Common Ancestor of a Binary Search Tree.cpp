/* Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” */

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if((root->val >= p->val && root->val <= q->val) or (root->val <= p->val && root->val >= q->val)) 
        	return root;
        
        if((root->val >= p->val && root->val >= q->val)) 
        	return lowestCommonAncestor(root->left, p, q);
        
        return lowestCommonAncestor(root->right, p, q);
    }
};