class Solution {
public:

    /* Method 1: Using Stack 

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
    */

    /* Method 2: Using Array or vector */

    int calPoints(vector<string>& operations) 
    {
        int n = operations.size(), ans = 0, cur_index = -1;
        int record[n];
        memset(record, 0, n);

        for(int i = 0; i < n; i++) {
            if(operations[i] == "C") {
                ans = ans - record[cur_index];
                cur_index--;
            } else if (operations[i] == "D") {
                record[cur_index + 1] = record[cur_index] * 2;
                ans = ans + record[cur_index + 1];
                cur_index++;
            } else if (operations[i] == "+") {
                int a = record[cur_index];
                int b = record[cur_index - 1];
                record[cur_index + 1] = a + b;
                ans = ans + record[cur_index + 1];
                cur_index++;
            } else {
                cur_index++;
                int score = stoi(operations[i]);
                record[cur_index] = score; 
                ans = ans + record[cur_index];
            }    
        }

        return ans;
    }
};