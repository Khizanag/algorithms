/* Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 */

class Solution {
public:
    void travel(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || i >= grid.size() 
           || j < 0 || j >= grid[i].size() 
           || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        travel(i-1, j, grid);
        travel(i, j-1, grid);
        travel(i, j+1, grid);
        travel(i+1, j, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '0') continue;;
                travel(i, j, grid);
                result++;
            }
        }
        return result;
    }
};