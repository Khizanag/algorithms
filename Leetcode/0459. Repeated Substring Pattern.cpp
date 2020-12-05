/* Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000. */

class Solution {
public:
	template <typename T> 
	vector<T> Get_Divisors(T n){
		T root = sqrt(n); vector<T> v;
		for(T i = 1; i <= root; i++){
			if(n % i == 0) {
				v.push_back(i);
				T div = n/i;
				if(div != i)
					v.push_back(div);
			}
		}
		return v; 
	}
	
	bool repeatedSubstringPattern(string s) {
		int len = s.size();
		if(len <= 1) return false;
		auto divs = Get_Divisors(len); // 0th is 1, 1th in n
		divs.push_back(1); // avoid deleting 1th elem
		for(int i = 2; i < divs.size(); i++)
		{
			int div = divs[i];
			bool found = true;
			for(int j = div; j < len; j++)
				if(s[j] != s[j%div])
					{ found = false; break; }
			if(found) return true;
		}
		return false;
	}
};