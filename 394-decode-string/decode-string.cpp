class Solution {
public:

    /* Method 1: two stack method */

    string decodeString(string s) 
    {
        string cur;
        stack<string> st_string;
        stack<int> st_num;
        int num = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= 48 && s[i] <= 57) {
                num = num * 10 + (s[i] - 48);
            } else if (s[i] == '[') {
                st_num.push(num);
                st_string.push(cur);
                cur = "";
                num = 0;
            } else if (s[i] == ']') {
                string prev = st_string.top();
                st_string.pop();

                int count = st_num.top();
                st_num.pop();

                while(count) {
                    prev = prev + cur;
                    count--;
                }

                cur = prev;

            } else {
                cur = cur + s[i];
            }
        }

        return cur;
    }
};