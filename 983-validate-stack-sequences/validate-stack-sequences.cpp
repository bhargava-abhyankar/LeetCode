class Solution {
public:

    /* Method 1: Using stack */

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int j = 0;
        stack<int> st;

        for(int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);

            while(!st.empty() && st.top() == popped[j]) {
                j++;
                st.pop();
            }
        }

        return j == popped.size();    
    }
};