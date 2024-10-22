class Solution {
public:

    /* valid Parentheses basic problem with single type of bracket. This is not leetcode problem
       this for study as basic. 

    bool isValid(string s) 
    {
        int count = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                count++;
            } else {
                if(count == 0)
                    return false;
                count--;
            }
        }
        return count == 0 ? true: flase;
    }

    */

    bool isValid(string s)
    { 
	    stack<char> st;
	
	    for(int i = s.length()-1; i >= 0 ; i--) {
		    if(s[i] == ')' || s[i] == '}' || s[i] == ']')
			    st.push(s[i]);
		    else if ((s[i] == '(' && !st.empty() && st.top() == ')') ||
		            (s[i] == '{' && !st.empty() && st.top() == '}') ||
				    (s[i] == '[' && !st.empty() && st.top() == ']')) {
			    st.pop();
		    } else {
			    return false;
		    }
	    }
	
	    return st.empty(); 
    }
};