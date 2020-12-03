/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle. */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        int l = 0, r = 0;
        
        while(r < nums.size())
        {
            if(r == l)
            {
                curr_sum += nums[r++];
                // max_sum = max(max_sum, curr_sum);
            }
            else if(curr_sum < 0 || nums[l] < 0)
            {
                max_sum = max(max_sum, curr_sum);
                curr_sum -= nums[l++];
            }
            else // if(nums[r] >= 0)
            {
                max_sum = max(max_sum, curr_sum);
                curr_sum += nums[r++];
            }
            
        }
        
        while(l < r)
        {
            max_sum = max(max_sum, curr_sum);
            curr_sum -= nums[l++];
        }
        
        return max_sum;
    }
};