/* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int i, int j) Return the sum of the elements of the nums array in the range [i, j] inclusive (i.e., sum(nums[i], nums[i + 1], ... , nums[j])) */

class NumArray {
public:
    vector<int> DP;
    vector<int> A;
    NumArray(vector<int>& nums) {
        DP.resize(nums.size(), 0);
        if(!nums.empty())
            DP[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            DP[i] = DP[i-1] + nums[i];
        }
        A = nums;
    }
    
    int sumRange(int i, int j) {
        return DP[j] - DP[i] + A[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */