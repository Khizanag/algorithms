/* Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */

class Solution {
public:
	string removeDuplicateLetters(string s) {
		string R = "";
		vector<int>  F(26, 0);   // count of each letter
		vector<bool> B(26, 0);  // is letter used
		for(char c : s)         // count frequencies of each letter
			F[c-'a']++;
		
		for(char c : s)
		{
			int i = c - 'a';    // index of each letter
			F[i]--;             // count of this letter is less by one after this index
			if(B[i]) continue;  // string already contains this letter

			while(!R.empty() && R.back() > c && F[R.back()-'a'] > 0)
			{
				B[R.back()-'a'] = false;
				R.pop_back();
			}
			R.push_back(c);     // add this letter to the result
			B[i] = true;        // string contains this letter
		}
		
		return R;
	}
};