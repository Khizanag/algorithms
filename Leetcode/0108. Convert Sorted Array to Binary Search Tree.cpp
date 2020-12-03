
/* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. */


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
    TreeNode* fn(vector<int> &v, int l, int r)
    {
        if(l >= r)
            return NULL;
        TreeNode * thisNode = new TreeNode(v[(l+r)/2]);
        thisNode->left = fn(v, l, (l+r)/2);
        thisNode->right = fn(v, (l+r)/2+1, r);
        return thisNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fn(nums, 0, nums.size());
    }
};