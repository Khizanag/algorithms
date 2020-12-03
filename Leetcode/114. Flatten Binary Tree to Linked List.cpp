/* Given a binary tree, flatten it to a linked list in-place. */

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
    void pre_order(TreeNode* node, queue<TreeNode*> &q){
        if(node == NULL) return;
        q.push(node);
        pre_order(node->left, q);
        pre_order(node->right, q);
    }
    
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        pre_order(root, q);
        if(q.empty()) return;
        TreeNode* saved = q.front(); q.pop();
        saved->left = NULL;
        while(!q.empty()){
            TreeNode* popped = q.front(); q.pop();
            saved->right = popped;
            popped->left = NULL;
            saved = popped;
        } saved->right = NULL;
    }
};