/* Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k. */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.count(nums[i]) and (i - mp[nums[i]]) <= k)
                return true;
            else
                mp[nums[i]] = i;
        }
        return false;
    }
};