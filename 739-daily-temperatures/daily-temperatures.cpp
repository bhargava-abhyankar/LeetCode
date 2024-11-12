class Solution {
public:

    /* Brute force

    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> ans(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++) {
            for(int j = i + 1; j < temperatures.size(); j++) {
                if(temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    break;
                }
            }
        }    

        return ans;
    }

    */

    /* method 1: Using stack */

    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); i++) {

            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }

};