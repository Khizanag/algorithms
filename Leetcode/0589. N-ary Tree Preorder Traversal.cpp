/* Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples). */

/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/

class Solution {
public:
	void helper(Node* root, vector<int> &v)
	{
		if(root == NULL)
			return;
		v.push_back(root->val);
		for(Node* node : root->children)
			helper(node, v);
	}
	
	vector<int> preorder(Node* root) {
		vector<int> v;
		helper(root, v);
		return v;
	}
};