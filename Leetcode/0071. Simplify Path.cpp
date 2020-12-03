/* Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period '.' refers to the current directory. Furthermore, a double period '..' moves the directory up a level.

Note that the returned canonical path must always begin with a slash '/', and there must be only a single slash '/' between two directory names. The last directory name (if it exists) must not end with a trailing '/'. Also, the canonical path must be the shortest string representing the absolute path. */

class Solution {
public:
    string simplifyPath(string path) 
    {
        vector<string> st;
        for(int i = 0; i < path.size(); i++)
        {
            while(i < path.size() && path[i] == '/')
                i++;
            
            if(i >= path.size())
                break;

            if(path[i] == '.' && i+1 < path.size() && path[i+1] == '.' 
              && (i+2 >= path.size() || path[i+2] == '/')) {
                if(!st.empty())
                    st.pop_back();
                i++; // jump over second '.'
            } else if(path[i] == '.' && (i+1 >= path.size() || path[i+1] == '/')) {
                continue;
            } else {
                string filename = "";
                while(i < path.size() && path[i] != '/')
                    filename += path[i++];
                i--;
                st.push_back(filename);
            }
        }
        
        string R = "";
        for(string r : st)
            R += "/" + r;

        if(R == "")
            return "/";
        else
            return R;
    }
};