/* You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S. */

class Solution {
public:

	int findTargetSumWays(vector<int>& nums, long long s) {
		if(nums.size() == 0) return (s == 0);
		
		int last = nums[nums.size()-1]; nums.pop_back();
		int plus = findTargetSumWays(nums, s + last);
		int minus = findTargetSumWays(nums, s - last);
		nums.push_back(last); // backtracking
		
		return plus + minus;
	}
};