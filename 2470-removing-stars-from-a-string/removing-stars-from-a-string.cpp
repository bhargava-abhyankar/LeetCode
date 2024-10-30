class Solution {
public:

    /* Method 1: Using two pointer. In place replacement

    string removeStars(string s) 
    {
        int j = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '*') {
                j--;
            } else {
                s[j] = s[i];
                j++;
            }
        }

        return s.substr(0, j);
    }

    */

    /* Method 2: stack based approach */

    string removeStars(string s) 
    {
        string ans = "";

        for(int i = 0; i < s.length(); i++) {
            if(ans.length() > 0 && s[i] == '*') {
                ans.pop_back();
            } else if (s[i] != '*') {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }

};