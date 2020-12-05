/* One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

	 _9_
	/   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3". */

class Solution {
public:
	bool isValidSerialization(string s) 
	{
		int count = 1;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == ',')
				continue;
			else if(s[i] == '#')
			{
				if(count > 0)
					count--;
				else
					return false;
			}
			else
			{
				if(count > 0)
					count += 1;
				else
					return false;
				while(i < s.size() && isdigit(s[i]))
					i++;
				i--;
			}
		}
		return count == 0;
	}
};


// ----------------------------------------------------------------

class Solution {
public:
	bool isValidSerialization(string s) 
	{
		stack<char> st; st.push('g');
		bool lastWasDigit = false;
		for(char c : s)
		{
			if(c == ',')
			{
				lastWasDigit = false;
				continue;
			}
			else if(c == '#')
			{
				if(st.empty())
					return false;
				else
					st.pop();
				lastWasDigit = false;
			}
			else
			{
				if(lastWasDigit)
					continue;
				else
					lastWasDigit = true;
				if(st.empty())
					return false;
				else
					 st.pop();
				
				st.push(c);
				st.push(c);
			}
		}
		return st.empty();
	}
};