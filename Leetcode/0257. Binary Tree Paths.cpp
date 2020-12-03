/* Given a binary tree, return all root-to-leaf paths.

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
    void fn(TreeNode * root, vector<string> &v, string cur)
    {
        if(root == NULL)
            return;
        cur += to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            v.push_back(cur);
        } else {
            cur += "->";
            fn(root->left, v, cur);
            fn(root->right, v, cur);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        fn(root, v, "");
        return v;
    }
};