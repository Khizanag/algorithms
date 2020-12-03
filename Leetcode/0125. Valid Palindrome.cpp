/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(!isalpha(s[l]) and !isdigit(s[l]))
                l += 1;
            else if(!isalpha(s[r]) and !isdigit(s[r]))
                r -= 1;
            else if(isdigit(s[l]) != isdigit(s[r]))
                return false;
            else if(toupper(s[l]) == toupper(s[r]))
                l+=1, r-=1;
            else
                return false;
        }
        return true; // if there were no error, then it is valid
    }
};