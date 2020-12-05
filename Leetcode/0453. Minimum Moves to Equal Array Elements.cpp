/* Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1. */

class Solution {
public:
	int minMoves(vector<int>& A) {
		if(A.empty())
			return 0;
		
		long mn = A[0];
		long sum = 0;
		for(long i : A)
		{
			mn = min(mn, i);
			sum += i;
		}
			
		return sum - mn*A.size();
	}
};