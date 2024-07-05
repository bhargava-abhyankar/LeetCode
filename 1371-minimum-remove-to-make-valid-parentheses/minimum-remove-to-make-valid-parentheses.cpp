class Solution {
public:

    /* First approach */

    string minRemoveToMakeValid(string s) 
    {
        string ans;
        stack<pair<char, int>> st;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push({'(', i});
            } else if (s[i] == ')' && st.empty() != true && st.top().first == '(') {
                st.pop();
            } else if (s[i] == ')' ) {
                st.push({')', i});
            }
        }

        for(int i = s.length()-1; i >= 0; i--) {
            if(st.empty() != true && st.top().second == i) {
                st.pop();
                continue;
            }
            ans.push_back(s[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    
};