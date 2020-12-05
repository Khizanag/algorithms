/* Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note. */

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> F(26, 0);
		for(char c : magazine)
			F[c-'a'] += 1;
		for(char c : ransomNote)
		{
			if(--F[c-'a'] < 0)
				return false;
		}
		return true;
	}
};