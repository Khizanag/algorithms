/* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children. */

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
    bool fn(TreeNode* root, int sum, int curSum)
    {
        if(!root)
            return false;
        if(!root->left && !root->right)
           return curSum+root->val == sum;
        return fn(root->left, sum, curSum + root->val)
            || fn(root->right, sum, curSum + root->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return root && fn(root, sum, 0);
    }
};