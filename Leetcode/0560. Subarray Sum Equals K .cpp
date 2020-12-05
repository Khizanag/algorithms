/* Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k. */

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) 
	{
		int sum = 0;
		int count = 0;
		int n = nums.size();
		
		unordered_map<int, int> mp{ {0,1} };
		
		for(int num : nums)
		{
			sum += num;
			count += mp[sum-k];
			mp[sum]++;
		}
		  
		return count;
	}
};