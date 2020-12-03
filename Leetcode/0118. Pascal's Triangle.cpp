/* Given a non-negative integer numRows, generate the first numRows of Pascal's triangle. */

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> vv; // pascal's triangle
        vector<int> v = {1}; // last row
        
        for(int numRow = 0; numRow < numRows; numRow+=1)
        {
            vv.push_back(v);
            vector<int> row = {1};
            
            for(int i = 1; i < v.size(); i++)
            {
                row.push_back(v[i-1] + v[i]);
            } row.push_back(1);
            v = row;
        }
        
        return vv;
    }
};