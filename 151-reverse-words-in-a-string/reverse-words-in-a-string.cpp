class Solution {
public:
    void copy_word(string &s, int j, int i, string &ans)
    {
        while(j <= i) {
            ans.push_back(s[j]);
            j++;
        }
        ans.push_back(' ');        
    }

    string reverseWords(string s) 
    {
        string ans;
        int i = -1, j = s.length()-1;

        while(j >= 0) {
            while (j >= 0 && s[j] == ' ') {
                j--;
            }
            i = j;
            while (j >= 0 && s[j] != ' ') {
                j--;
            }

            if(j >= -1 && i >= 0) {
                copy_word(s, j+1, i, ans);
            }
        }
        
        ans.pop_back();      
        return ans;    
    }
};