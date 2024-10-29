class Solution {
public:

    int evalRPN(vector<string>& tokens) 
    {
        int ans;
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {
            int a, b;

            if (tokens[i] == "+") {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(int(a + b));

            } else if(tokens[i] == "-") {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(int(b - a));
            } else if(tokens[i] == "*") {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(int(a * b));
            } else if(tokens[i] == "/") {
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(int(b / a));
            } else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};