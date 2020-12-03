/* The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int rec(TreeNode * root)
    {
        if(root == NULL)
            return 100000000;
        if(root->left == NULL && root->right == NULL)
            return 1;
        return 1 + min(rec(root->left), rec(root->right));
    }
    
    int minDepth(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int leftRec = rec(root->left);
        int rightRec = rec(root->right);
        if(root->left == NULL)
            return 1 + rightRec;
        if(root->right == NULL)
            return 1 + leftRec;
        
        return 1 + min(leftRec, rightRec);
    }
};