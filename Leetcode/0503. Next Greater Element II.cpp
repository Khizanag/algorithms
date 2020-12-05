/* Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number. */

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> v(2*nums.size());
		for(int i = 0; i < nums.size(); i++)
		{
			v[i] = nums[i];
			v[i+nums.size()] = nums[i];
		}
		
		
		stack<int> st;
		vector<int> result(nums.size());
		for(int i = v.size()-1; i >= 0; i--)
		{
			while(!st.empty() && st.top() <= v[i])
				st.pop();
			
			if(i < result.size())
			{
				if(st.empty())
					result[i] = -1;
				else
					result[i] = st.top();
			}
			
			st.push(v[i]);
		}
		return result;
	}
};