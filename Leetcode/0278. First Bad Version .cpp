/* You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API. */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = (long long)(n)+1;
        long long lastBad = -1;
        while(l < r)
        {
            long long m = (l + r) / 2;
            if(isBadVersion(m))
                lastBad = m, r = m;
            else
                l = m + 1;
        }
        return lastBad;
    }
};