class Solution {
public:
    string reverseOnlyLetters(string s) 
    {
        int i = 0, j = s.length()-1;

        while(i < j) {
            while ( (i < j) && !((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))) {
                i++;
            }
            while ( (i < j) && !((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122))) {
                j--;
            }
            if(i < j) {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }          
        }
        return s;   
    }
};