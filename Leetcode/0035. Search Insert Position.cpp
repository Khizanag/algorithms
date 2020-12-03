/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. */

class Solution {
public:
    int searchInsert(vector<int>& A, int T) {
        int l = 0, r = A.size();
        while(l < r) {
            int m = (l + r) / 2;
            
            if(A[m] == T)
                return m;
            else if(A[m] > T){
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
};