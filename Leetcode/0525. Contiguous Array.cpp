/* Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. */

class Solution {
public:
	int findMaxLength(vector<int>& A) 
	{    
		unordered_map<int, int> mp; // sum, first index of this sum
		mp[0] = -1; // initially sum is 0
		
		int sum = 0;
		int maxLen = 0;
		
		for(int i = 0; i < A.size(); i+=1)
		{
			sum += (A[i] == 1 ? 1 : -1); // use -1 instade of 0
			if(mp.count(sum)) {
				maxLen = max(maxLen, i - mp[sum]);
			} else {
				mp[sum] = i;
			}
		}
		
		return maxLen;
	}
};