/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row. */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto &v : matrix)
        {
            for(auto &elem : v)
            {
                if(elem == target)
                    return true;
            }
        }
        return false;
    }
};