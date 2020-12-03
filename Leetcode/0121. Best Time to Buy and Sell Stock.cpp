/* Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one. */

class Solution {
public:
    int maxProfit(vector<int>& A) {
        int leftMax = INT_MIN;
        int maxDif = 0; 
        for(int i = A.size()-1; i >= 0; i-=1)
        {
            leftMax = max(leftMax, A[i]);
            maxDif = max(maxDif, leftMax-A[i]);
        }
        return maxDif;
    }
};