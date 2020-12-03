/* The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence. */

class Solution {
public:
    string countAndSay(int n) {
        string last = "1";
        
        for(int i = 1; i < n; i++){
            int count = 0;
            char lastC = last[0];
            string newStr = "";
            for(int j = 0; j < last.size(); j++){
                if(last[j] == lastC) count++;
                else {
                    newStr = newStr + to_string(count) + lastC;
                    lastC = last[j];
                    count = 1;
                }
            }
            newStr = newStr + to_string(count) + lastC;
            last = newStr;
        }
        
        return last;
    }
};