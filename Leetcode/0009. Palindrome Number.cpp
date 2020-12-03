/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Follow up: Could you solve it without converting the integer to a string?
*/
class Solution {
public:
    bool isPalindrome(int x) {
        string x_str = to_string(x);
        string rev_x_str = x_str;
        reverse(rev_x_str.begin(), rev_x_str.end());
        return x_str == rev_x_str;
    }
};