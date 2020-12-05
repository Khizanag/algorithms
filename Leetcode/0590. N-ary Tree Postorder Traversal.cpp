/* Given an n-ary tree, return the postorder traversal of its nodes' values.

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
	void fn(Node * root, vector<int> &v)
	{
		if(root == NULL)
			return;
		for(auto &node : root->children)
			fn(node, v);
		v.push_back(root->val);
	}
	
	vector<int> postorder(Node* root) {
		vector<int> v;
		fn(root, v);
		return v;
	}
};