// Given a string s, find the length of the longest substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> mp;
        
        int result = 0;
        
        for(int l = 0, r = 0; r < s.size(); r++)
        {
            if(mp.count(s[r]) && mp[s[r]] >= l)
                l = mp[s[r]] + 1;
            
            mp[s[r]] = r;

            result = max(result, r-l+1);
        }
        
        return result;
    }
};