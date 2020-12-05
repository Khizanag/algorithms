/* Given an integer, return its base 7 string representation. */

class Solution {
public:
	string convertToBase7(int num)
	{
		bool isNegative = num < 0;
		if(isNegative)
			num = -num;
		string s = "";
		while(num != 0)
		{
			int rem = num % 7;
			s += ('0' + rem);
			num /= 7;
		}
		if(s.empty()) s += "0";
		if(isNegative) s += "-";
		reverse(s.begin(), s.end());
		return s;
	}
};