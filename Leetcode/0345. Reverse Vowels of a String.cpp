/* Write a function that takes a string as input and reverse only the vowels of a string. */

class Solution {
public:
    const unordered_set<int> VOWELS = { 'a', 'e', 'i', 'o', 'u'};
    
    bool is_vowel(char c)
    {
        return VOWELS.count(tolower(c)) > 0;
    }
    
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        while(l < r)
        {
            if(VOWELS.count(tolower(s[l])) == 0)
                l+=1;
            else if(VOWELS.count(tolower(s[r])) == 0)
                r-=1;
            else {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l+=1, r-=1;
            }
        }
        return s;
    }
};