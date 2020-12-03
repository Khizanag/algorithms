/* Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity? */

class Solution {
public:
    int trailingZeroes(int n) {
        int pow_of_5 = 5;
        int count = 0;
        while(pow_of_5 <= n)
        {
            count += n / pow_of_5;
            pow_of_5 *= 5;
        }
        return count;
    }
};