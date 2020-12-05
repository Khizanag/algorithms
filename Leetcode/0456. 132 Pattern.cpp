/* Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution? */

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int n = nums.size();
		
		vector<int> Lmin(n);
		Lmin[0] = INT_MAX;
		for(int i = 1; i < n; i++)
			Lmin[i] = min(Lmin[i-1], nums[i-1]);
		
		stack<int> st;
		for(int i = n-1; i >= 0; i--)
		{
			while(!st.empty() && st.top() <= Lmin[i])
				st.pop();
			if(!st.empty() && st.top() < nums[i])
				return true;
			st.push(nums[i]);
		}
		
		return false;
	}
};