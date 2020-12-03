/* Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x. */

class Solution {
public:
    int countBits(int n){
        int count = 0;
        while(n){
            count++;
            n &= (n-1);
        } return count;
    }
    
    bool isPowerOfTwo(int n) {
        return (n < 1) ? false : countBits(n) == 1;
    }
};