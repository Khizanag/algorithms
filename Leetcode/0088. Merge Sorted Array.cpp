/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
*/

class Solution {
public:
    void merge(vector<int>& A, int aLen, vector<int>& B, int bLen) {
        int ap = aLen-1, bp = bLen - 1, wp = aLen+bLen-1;
        
        while(ap >= 0 and bp >= 0) 
        {
            if(A[ap] > B[bp])
                A[wp--] = A[ap--];
            else
                A[wp--] = B[bp--];
        }
        
        while(ap >= 0)
            A[wp--] = A[ap--];
        while(bp >= 0)
            A[wp--] = B[bp--];
    }
};