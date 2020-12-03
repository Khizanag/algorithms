/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M. */

class Solution {
public:
    int romanToNum(char c){
        switch(c){
                case 'I' : return 1;
                case 'V' : return 5;
                case 'X' : return 10;
                case 'L' : return 50;
                case 'C' : return 100;
                case 'D' : return 500;
                case 'M' : return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        
        int mx = 0;
        int result = 0;
        
        for(int i = s.size()-1; i >= 0; i--){
            char c = s[i];
            int num = romanToNum(c);
            
            if(num < mx) result -= num;
            else result += num;
                
            mx = max(mx, num); // update
        }
        return result;
    }
};