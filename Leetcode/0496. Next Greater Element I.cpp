/* You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number. */

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> mp;
		
		stack<int> st;
		
		for(int a : nums2)
		{
			while(!st.empty() && a > st.top())
			{
				int top = st.top(); st.pop();
				mp[top] = a;
			}
			st.push(a);
		}
		
		while(!st.empty())
		{
			mp[st.top()] = -1; st.pop();
		}
		
		vector<int> result(nums1.size());
		for(int i = 0; i < nums1.size(); i++)
			result[i] = mp[nums1[i]];
		return result;
	}
};