/* You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island. */

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int N = grid.size();
		int M = grid[0].size();
		int count = 0;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(grid[i][j] == 1)
				{
					if(i == 0   || grid[i-1][j] == 0) count+=1;
					if(i == N-1 || grid[i+1][j] == 0) count+=1;
					if(j == 0   || grid[i][j-1] == 0) count+=1;
					if(j == M-1 || grid[i][j+1] == 0) count+=1;
				}
			}
		}
		return count;
	}
};