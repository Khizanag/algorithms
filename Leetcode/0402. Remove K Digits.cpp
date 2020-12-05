/* Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:

The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero. */

class Solution {
public:
	string removeKdigits(string num, int k)
	{
		string st = "";
		for(int i = 0; i < num.size(); i++)
		{
			while(k > 0 && !st.empty() && st.back() > num[i])
			{
				st.pop_back();
				k--;
			}
			if(num[i] != '0' || !st.empty())
				st.push_back(num[i]);
		}
		st = st.substr(0, st.size() - k);
		return st == "" ? "0" : st;
	}
};