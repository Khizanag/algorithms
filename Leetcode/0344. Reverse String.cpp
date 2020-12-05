/* Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters. */

class Solution {
public:
	void reverseString(vector<char>& s) {
		reverse(s.begin(), s.end());
	}
};

// ----------------------------------------------------------------

class Solution {
public:
	void reverseString(vector<char>& s) {
		for(int i = 0; i < s.size()/2; i++)
			swap(s[i], s[s.size()-i-1]);
	}
};