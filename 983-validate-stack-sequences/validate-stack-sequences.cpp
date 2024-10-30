class Solution {
public:

    /* Method 1: Using stack 

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

    */

    /* Method 2: Two Pointer. Use given array pushed as stack */

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i = 0, j = 0;

        for(int k = 0; k < pushed.size(); k++) {
            pushed[i] = pushed[k];
            i++;

            while(i > 0 && pushed[i-1] == popped[j]) {
                j++;
                i--;
            }
        }

        return i == 0;
    }

};