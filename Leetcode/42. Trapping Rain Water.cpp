/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining. */

class Solution {
public:
    int trap(vector<int>& H)
    {
        int sum = 0;
        stack<int> st;
        for(int i = 0; i < H.size(); i++)
        {
            while (!st.empty() && H[i] > H[st.top()])
            {
                int top = st.top(); st.pop();
                if (!st.empty())
                {
                    int width = i - st.top() - 1;
                    int height = min(H[i], H[st.top()]) - H[top];
                    sum += width * height;   
                }
            }
            st.push(i);
        }
        return sum;
    }
};