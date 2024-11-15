class Solution {
public:

    /* Method 1: two stack method 

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

                // Most difficult piece to understand 

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

    */

    /* method 2: Using recursion */

    string recursive_decode(string &s, int &cur_index)
    {
        string ans = "";
        int num = 0;

        while(cur_index < s.length() && s[cur_index] != ']') {
            if(s[cur_index] >= 48 && s[cur_index] <= 57) {
                while(cur_index < s.length() &&  s[cur_index] >= 48 && s[cur_index] <= 57) {
                    num = num * 10 + s[cur_index] - 48;
                    cur_index++;
                }

                cur_index++; //incrementing '['

                string prev = recursive_decode(s, cur_index);

                while(num > 0) {
                    ans = ans + prev;
                    num--;
                }

                cur_index++; //incrementing ']' 

            } else {
                ans = ans + s[cur_index];
                cur_index++;
            }
        }

        return ans;

        
    }

    string decodeString(string s) 
    {
        int index = 0;
        string ans = recursive_decode(s, index);
        return ans;
    }

};