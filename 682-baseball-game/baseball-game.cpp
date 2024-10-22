class Solution {
public:

    int calPoints(vector<string>& operations) 
    {
        int ans = 0;
        stack<int> st;

        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "C") {
                if(!st.empty()) {
                    st.pop();
                }
            } else if (operations[i] == "D") {
                if(!st.empty()) {
                    st.push(st.top() * 2);
                }
            } else if (operations[i] == "+") {
                if(st.size() >= 2) {
                    int a = st.top(); st.pop();
                    int b = st.top(); st.pop();
                    int add = a + b;
                    st.push(b);
                    st.push(a);
                    st.push(add);
                }
            } else {
                st.push(stoi(operations[i]));
            }
        }

        while(!st.empty()) {
            ans = ans + st.top();
            st.pop();
        }

        return ans;
    }
};