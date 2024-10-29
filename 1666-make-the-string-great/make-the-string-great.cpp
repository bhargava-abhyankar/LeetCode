class Solution {
public:

    /* Method 1: Simple Brute force */
    
    string makeGood(string s) 
    {
        while(s.length() > 1) {

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
};