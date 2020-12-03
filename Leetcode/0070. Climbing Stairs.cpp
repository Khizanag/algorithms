/* You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> DP(n+1, 0);
        DP[0] = 0;
        DP[1] = 1;
        DP[2] = 2;
        for(int i = 3; i <= n; i+=1)
        {
            DP[i] = DP[i-1] + DP[i-2];
        }
        return DP[n];
    }
};