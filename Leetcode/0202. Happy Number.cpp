/* Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not. */

class Solution {
public:
    
    int get_updated_n(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        set<int> been;
        while(n != 1)
        {
            if(!been.count(n))
            {
                been.insert(n);
                n = get_updated_n(n);
            } else
                return false;
        }
        return true;
    }
};