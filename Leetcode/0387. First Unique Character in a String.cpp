/* Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1. */

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> F(26, 0);

		for(char c : s)
			F[c-'a'] += 1;
		
		for(int i = 0; i < s.size(); i++)
			if(F[s[i]-'a'] == 1)
				return i;

		return -1;
	}
};