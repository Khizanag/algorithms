/* Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector< vector<int> > f(n, vector<int>(26, 0));
        map<vector<int>, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++)
        {
            for(char c : strs[i])
                f[i][c-'a']++;
            mp[f[i]].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for(auto &pr : mp)
        {
            result.push_back(pr.second);
        }
        return result;
    }
};