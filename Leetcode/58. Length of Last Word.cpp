/* Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only. */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz = 0;
        while(s[s.size()-1] == ' ') s = s.substr(0, s.size()-1);
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ') return sz;
            else sz++;
        } return sz;
    }
};