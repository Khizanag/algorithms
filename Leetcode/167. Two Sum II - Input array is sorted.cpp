/*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& A, int T) {
        int l = 0, r = A.size()-1;
        while(l < r)
        {
            int sum = A[l] + A[r];
            if(sum < T)
                l += 1;
            else if(sum > T)
                r -= 1;
            else
                return {l+1, r+1};
        }
        return {-1, -1};
    }
};