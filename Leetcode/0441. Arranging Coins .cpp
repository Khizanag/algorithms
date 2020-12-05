/* You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer. */

class Solution {
public:
	int arrangeCoins(int n) {
		// 1+2+3+...+x = n
		// (1+x)*x/2   = n
		// x+x^2       = 2n
		// x^2+x+1/4   = 2n+1/4
		// (x+1/2)^2   = 2n+1/4
		// x+1/2       = sqrt(2n+1/4)
		// x           = sqrt(2*n+1/4) - 1/2

		return sqrt(2.0*n+0.25) - 0.5;
	}
};