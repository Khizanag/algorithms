/* Given a column title as appear in an Excel sheet, return its corresponding column number.*/

class Solution {
public:
    int titleToNumber(string s) {
        int n = 0;
        for(char c : s)
            n = n * 26 + (c-'A'+1);
        return n;
    }
};