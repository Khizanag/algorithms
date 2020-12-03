/* Given a positive integer, return its corresponding column title as appear in an Excel sheet. */

class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        
        while(n > 0)
        {
            if(n % 26 == 0) {
                s += 'Z';
                n = n/26 - 1;
            } else {
                s += ('A' + n%26 - 1);
                n/=26;
            }
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};