/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_count = 0;
        for(int i = 0; i < nums.size()-zero_count; i++)
        {
            if(nums[i] == 0)
            {
                zero_count++;
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                i--;
            }
        }
    }
};