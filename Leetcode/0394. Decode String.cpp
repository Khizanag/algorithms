/* Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4]. */

class Solution {
public:
	string decodeString(string s) {
		stack<int> ns;      // numbers
		stack<string> ss;   // strings
		
		ss.push("");
		
		for(int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if(isdigit(c))
			{
				int n = 0;
				while(i < s.size() && isdigit(s[i]))
				{
					n = n * 10 + (s[i] - '0');
					i++;
				} 
				ns.push(n);
				i--; // for loop will do i++ again
			}
			else
			{
				if(c == '[')
					ss.push("");
				else if(c == ']')
				{
					int count = ns.top(); ns.pop();
					string torepl = ss.top(); ss.pop();
					string str = "";
					for(int iCount = 0; iCount < count; iCount++)
					{
						str += torepl;
					}
					if(ss.empty())
						ss.push(str);
					else
						ss.top() += str;
				}
				else
					ss.top() += c;
			}
		}
		
		return ss.top();
	}
};