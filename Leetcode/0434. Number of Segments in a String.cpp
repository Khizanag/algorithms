/* You are given a string s, return the number of segments in the string. 

A segment is defined to be a contiguous sequence of non-space characters. */

class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int count = 0;
        while(ss >> s and ++count);
        return count;
    }
};