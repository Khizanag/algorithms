/* Given two binary strings a and b, return their sum as a binary string. */

class Solution {
public:
    string addBinary(string a, string b)
    {
        if(a.size() < b.size()) swap(a, b);
        
        bool saved = false;
        string s = "";
        
        for(int _i = 0; _i < b.size(); _i++)
        {
            int bi = (int)b.size() - _i - 1;
            int ai = (int)a.size() - _i - 1;
            int count = saved + (a[ai] == '1') + (b[bi] == '1');
            if(count % 2 == 1)
                s += '1';
            else 
                s += '0';
            
            saved = count >= 2;
        }

        for(int i = (int)a.size() - (int)b.size() - 1; i >= 0; i--)
        {
            int count = saved + (a[i] == '1');

            if(count % 2 == 1)
                s += '1';
            else 
                s += '0';
            
            saved = count >= 2;
        }
        
        if(saved)
            s += '1';
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};