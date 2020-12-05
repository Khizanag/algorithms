/* Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x. */

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        
        while(n > 1)
        {
            if(n % 4 == 0)
                n/=4;
            else
                return false;
        }
        return true;
    }
};