class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++){
            int d = target - nums[i];
            if(mp.count(d) && mp[d] != i) {
                return vector<int>{i, mp[d]};
            }
        }
        
        return vector<int>{};
    }
};