/* Given a binary tree, find the leftmost value in the last row of the tree. */

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
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> q;
		if(root)
			q.push(root);
		int result = root ? root->val : -1;
		while(!q.empty())
		{
			int size = q.size();
			for(int i = 0; i < size; i+=1)
			{
				TreeNode * node = q.front(); q.pop();
			
				if(i == 0)
					result = node->val;
				
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
		}
		return result;
	}
};