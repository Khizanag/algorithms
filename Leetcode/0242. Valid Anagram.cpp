/* Given two strings s and t , write a function to determine if t is an anagram of s. */

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> F1(26, 0), F2(26, 0);
        for(char c : s) F1[c - 'a']++;
        for(char c : t) F2[c - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(F1[i] != F2[i])
                return false;
        
        return true;
    }
};