class Solution {
public:

    /* Method 1: Simple Brute force. Time complexity O(n2)

    string makeGood(string s) 
    {
        while(s.length()) {

            bool is_pair_found = false;

            for(int i = 0; i < s.length()-1; i++) {
                if(abs(s[i] - s[i+1]) == 32) {
                    is_pair_found = true;
                    s = s.substr(0, i) + s.substr(i+2);
                    break;
                }
            }

            if(!is_pair_found)
                break;
        }

        return s; 
    }

    */

    /* Method 2: Using Recursion 

    string makeGood(string s)
    {
        if(s.length() == 0)
            return s;
        
        for(int i = 0; i < s.length()-1; i++) {

            if(abs(s[i] - s[i + 1]) == 32) {
                s = s.substr(0, i) + s.substr(i+2);
                return makeGood(s);
            }
        }

        return s;
    }

    */

    /* Method 3: Using stack */

    string makeGood(string s)
    {
        string ans;
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            if(!st.empty() && abs(st.top() - s[i]) == 32) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans; 
    }

};