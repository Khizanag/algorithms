/* Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order. */

class Solution {
public:
	int my_find(string &s, char toFind, int from)
	{
		for(int i = from; i < s.size(); i++)
		{
			if(s[i] == toFind)
				return i;
		}
		return string::npos;
	}
	
	string reverseWords(string s) {
		int l = 0;
		int r = my_find(s, ' ', l);
		while(r != string::npos)
		{
			reverse(s.begin()+l, s.begin()+r);
			l = r+1;
			r = my_find(s, ' ', l);
		} reverse(s.begin()+l, s.end()); // last word
		
		return s;
	}
};