//Given a 32-bit signed integer, reverse digits of an integer.

//Note:
//Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

class Solution {
public:
    
    int reverse(int x) {
        long long result = 0;
        while(x)
        {
            result *= 10;
            result += x%10;
            x /= 10;
        }
        if(abs(result) > INT_MAX)
            return 0;
        return result;
    }
};