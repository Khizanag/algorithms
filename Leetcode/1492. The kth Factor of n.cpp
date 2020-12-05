/* Given two positive integers n and k.

A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors. */

class Solution {
public:
    int kthFactor(int n, int k) 
    {  
        vector<int> factors;
        for(int i = 1; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                k--;
                if(k == 0)
                    return i;
                factors.push_back(i);
            }
        }

        if(factors.back() * factors.back() == n)    // is sqr root
            factors.pop_back();                     // so now every factor has pair that:
                                                    //      (factor * pr = n) and (factor != pr)
        if(k > factors.size())
            return -1;
        else
            return n / factors[factors.size() - k];
    }
};