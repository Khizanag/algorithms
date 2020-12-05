/* Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space. */

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		for(int n : nums)
		{
			n = abs(n);
			if(nums[n-1] > 0)
				nums[n-1] *= -1; // mark as visited
		}
		
		vector<int> v;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] > 0)
				v.push_back(i+1);
		}
		
		return v;
	}
};