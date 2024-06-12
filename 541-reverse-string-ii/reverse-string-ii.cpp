class Solution {
public:

    void reverse(string &s, int i, int j)
    {
        while(i < j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }

    string reverseStr(string s, int k) 
    {
        for(int i = 0; i < s.length(); i = i+2*k) {
            int j;
            if((s.length() -i) > k) {
                j = i + k -1;
            } else {
                j = s.length()-1;
            }
            reverse(s, i, j);
        }
        return s;
    }
};