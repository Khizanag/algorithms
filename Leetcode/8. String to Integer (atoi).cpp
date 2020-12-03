/* Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, 231 − 1 or −231 is returned.
*/

class Solution {
public:
    int myAtoi(string s) {
        long long n = 0;
        int i = 0;
        bool isNegative = false;
        
        while(i < s.size() && s[i] == ' ') // skip spaces
            i+=1;
        
        if((i < s.size() && s[i] == '-')) // skip -
        {
            i+=1;
            isNegative = true;
        } else if(i < s.size() && s[i] == '+')
            i += 1;
            
        for(; i < s.size(); i++)
        {
            if(!isdigit(s[i]))
                break;
            n = n * 10 + s[i] - '0';
            if(n > INT_MAX)
                return isNegative ? INT_MIN : INT_MAX;
        }
        if(isNegative)
            n = -n;

        return n;
    }
};