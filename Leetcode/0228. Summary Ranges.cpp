/* You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& A) {
        if(A.empty())
            return {};
        
        A.push_back(A.back());
        vector<string> v;
        int saved_index = 0;
        for(int i = 1; i < A.size(); i+=1)
        {
            if((long)A[i] != (long)A[i-1] + 1)
            {
                if(i - saved_index == 1)
                    v.push_back(to_string(A[saved_index]));    
                else
                    v.push_back(to_string(A[saved_index]) + "->" + to_string(A[i-1]));
                saved_index = i;
            }
        }

        return v;
    }
};