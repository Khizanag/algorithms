/* Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. */

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        
        while(num > 1) {
            cout << num << endl;
            if(num % 2 == 0)
                num/=2;
            else if(num % 3 == 0)
                num/=3;
            else if(num % 5 == 0)
                num/=5;
            else
                return false;
        }
        return true;
    }
};