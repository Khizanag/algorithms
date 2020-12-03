/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). */

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
    void buildV(TreeNode* root, vector<int> & v, int level)
    {
        if(root == NULL)
        {
            v.push_back(INT_MIN + level);
            return;
        }
        buildV(root->left, v, level+1);
        v.push_back(root->val);
        buildV(root->right, v, level+1);
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int> v;
        buildV(root,v, 0);
        for(int i = 0; i < v.size()/2; i++)
        {
            if(v[i] != v[v.size() - i - 1])
                return false;
        }
        return  true;
    }
}; 