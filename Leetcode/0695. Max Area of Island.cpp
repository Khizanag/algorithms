/* Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50. */

class Solution {
public:
	int DFS(int i, int j, vector<vector<int>> &M)
	{
		if(i < 0 || i >= M.size() || j < 0 || j >= M[i].size() || M[i][j] == 0)
			return 0;
		
		M[i][j] = 0;

		return 1
				+ DFS(i-1, j, M)
				+ DFS(i+1, j, M)
				+ DFS(i, j-1, M)
				+ DFS(i, j+1, M);
	}
	
	int maxAreaOfIsland(vector<vector<int>>& grid) 
	{
		int maxArea = 0;
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[i].size(); j++)
			{
				maxArea = max(maxArea, DFS(i, j, grid));
			}
		}
		return maxArea;
	}
};