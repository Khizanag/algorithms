/* Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        // create vector from words
        vector<string> strVec;
        while(true){
            int indexOfSpace = str.find(" ");
            if(indexOfSpace == string::npos){
                strVec.push_back(str);
                break;
            }
            strVec.push_back(str.substr(0, indexOfSpace));
            str = str.substr(indexOfSpace+1);
        }
        if(pattern.size() != strVec.size()) return false;
        
        map<char, string> mp;
        map<string, char> pm;
        for(int i = 0; i < pattern.size(); i++){
            char ch = pattern[i];
            if(mp.count(ch)){
                if(mp[ch] != strVec[i])  return false;
            } else {
                if(pm.count(strVec[i])) return false;
                mp[ch] = strVec[i];
                pm[strVec[i]] = ch;
            }
        }
        return true;
    }
};