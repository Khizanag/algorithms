/* Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself. */

class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int i;
        for(i = A.size()-1; i >= 0; i-=1)
        {
            if(A[i] == 9)
                A[i] = 0;
            else { A[i] += 1; break;}
        }
        if(i == -1)
            A.insert(A.begin(), 1);
        
        return A;
    }
};