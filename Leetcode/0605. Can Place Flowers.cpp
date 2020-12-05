/* You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule. */

class Solution {
public:
	bool canBePlanted(vector<int> &F, int i)
	{
		return i == F.size() - 1 or F[i+1] == 0;
	}
	
	int maxPossibleFlowersToPlant(vector<int> &F)
	{
		int count = 0;
		int i = 0;
		while(i < F.size())
		{
			if(F[i] == 0) {
				if(canBePlanted(F, i)) 
					count += 1, i += 2;
				else
					i += 1;
			} else {
				i += 2;
			}
		}
		return count;
	}
	
	bool canPlaceFlowers(vector<int>& F, int n) {
		return maxPossibleFlowersToPlant(F) >= n;
	}
};