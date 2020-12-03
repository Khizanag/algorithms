/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "". */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string prefix = strs[0];
        for(string &s : strs)
        {
            string new_prefix = "";
            int minLen = min(prefix.length(), s.length());
            for(int i = 0; i < minLen and s[i] == prefix[i]; i+=1)
            {
                new_prefix += s[i];
            }
            prefix = new_prefix;
        }
        return prefix;
    }
};