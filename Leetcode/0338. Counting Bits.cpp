/* Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array. */

class Solution {
public:
    int countOneBits(int n)
    {
        int result = 0;
        while(n != 0){
            result++;
            n &= (n-1);
        } return result;
    }
    
    vector<int> countBits(int num) 
    {
        vector<int> result;
        for(int i = 0; i <= num; i++){
            int nBits = countOneBits(i);
            result.push_back(nBits);
        } return result;
    }
};