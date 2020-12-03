/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        queue<string> q;   q.push("");
        queue<int> qo;  qo.push(n);
        queue<int> qc;  qc.push(n);

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string str      = q.front();  q.pop();
                int openersLeft = qo.front(); qo.pop();
                int closersLeft = qc.front(); qc.pop();
                if(openersLeft == 0 && closersLeft == 0)
                {
                    v.push_back(str);
                    continue;
                }
                
                if(openersLeft < closersLeft)
                {
                    q.push(str + ")");
                    qo.push(openersLeft);
                    qc.push(closersLeft-1);
                }
                if(openersLeft > 0)
                {
                    q.push(str + "(");
                    qo.push(openersLeft-1);
                    qc.push(closersLeft);
                }
            }
        }
        return v;
    }
};