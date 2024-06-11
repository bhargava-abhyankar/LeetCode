class Solution {
public:
    bool isPalindrome(string s) 
    {
        for(int i = 0, j = s.length()-1 ; i < j; i++, j--) {
            while((i < j) && !((s[i] >= 48 && s[i] <=57) || (s[i] >= 65 && s[i] <=90 ) || (s[i] >= 97 && s[i] <=122))) {
                i++;
            }
            while ((i < j) && !((s[j] >= 48 && s[j] <=57) || (s[j] >= 65 && s[j] <=90 ) || (s[j] >= 97 && s[j] <=122))) {
                j--;
            }

            if(s[i] != s[j]) {
                if((s[i] >= 48 && s[i] <=57) || ((s[j] >= 48 && s[j] <=57))) {
                    return false;
                }
                else if((abs(s[i]- s[j]) != 0) && ((abs(s[i] - s[j]) != 32))) {
                    return false;
                }
            }
            
        }

        return true;
    }
};