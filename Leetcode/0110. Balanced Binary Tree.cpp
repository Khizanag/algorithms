/* Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1. */

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
    pair<bool, int> fn(TreeNode * root)
    {
        if(root == NULL)
            return {true, 0};
        auto pr1 = fn(root->left);
        auto pr2 = fn(root->right);
        return {
            abs(pr1.second - pr2.second) <= 1 && pr1.first && pr2.first, 
            max(pr1.second, pr2.second) + 1
        };
    }
    
    bool isBalanced(TreeNode* root) {
        return fn(root).first;
    }
};