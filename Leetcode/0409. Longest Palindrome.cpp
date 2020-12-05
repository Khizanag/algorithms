/* Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here. */

class Solution {
public:
	int longestPalindrome(string s) {
		vector<int> f(26,0);
		vector<int> F(26,0);
		for(char c : s)
		{
			if(isupper(c))
				F[c-'A']+=1;
			else
				f[c-'a']+=1;
		}
			
		
		bool oddUsed = false;
		int count = 0;
		
		for(int i : F)
		{
			count += (i - i % 2);
			if(i % 2 == 1 and !oddUsed)
				count += 1, oddUsed = true;
		}
		
		for(int i : f)
		{
			count += (i - i % 2);
			if(i % 2 == 1 and !oddUsed)
				count += 1, oddUsed = true;
		}
		
		return count;
	}
};