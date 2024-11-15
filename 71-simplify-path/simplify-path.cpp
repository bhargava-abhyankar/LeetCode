class Solution {
public:

    string simplifyPath(string path) 
    {
        stack<string> st;
        string cur = "";

        for(int i = 0; i <= path.length(); i++) {
            /* first condition is required to handle last word without / */
            
            if( i == path.length() || path[i] == '/') { 
                if(cur == "..") {
                    if(!st.empty()) {
                        st.pop();
                    }
                } else if (cur != "" && cur != ".") {
                    st.push(cur);
                }    
                cur = "";
            } else {
                cur = cur + path[i];
            }
        }

        string res;
        while(!st.empty()) {
            res = "/" + st.top() + res; //not intutive. check carefully.
            st.pop();
        }

        return res.empty() ? "/" : res;
    }
};