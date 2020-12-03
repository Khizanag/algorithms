/* You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? */

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
    
    void inOrder(TreeNode * root, vector<int> &v)
    {
        if(!root)
            return;
        inOrder(root->left, v);
        
        
        // check for O(n)
        int index = (int)v.size()-1;
        for(; index >= 0; index-=1)
            if(root->val > v[index])
                break;

        v.insert(v.begin() + (index + 1), root->val);
        
        
        inOrder(root->right, v);
    }
    
    void loadValuesIntoTree(TreeNode* root, vector<int> &v, int &p)
    {
        if(!root)
            return;
        loadValuesIntoTree(root->left, v, p);
        root->val = v[p++];
        loadValuesIntoTree(root->right, v, p);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        // sort(v.begin(), v.end());
        int p = 0;
        loadValuesIntoTree(root, v, p);
    }
};