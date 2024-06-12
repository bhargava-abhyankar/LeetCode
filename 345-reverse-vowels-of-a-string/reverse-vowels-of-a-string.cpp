class Solution {
public:
    string reverseVowels(string s) 
    {
        int i = 0, j = s.length()-1;

        while(i < j) {

            while(i < j) {
                char x = tolower(s[i]); 
                if ( x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u') {
                    i++;
                } else {
                    break;
                }
            }

            while(i < j) {
                char y = tolower(s[j]); 
                if ( y != 'a' && y != 'e' && y != 'i' && y != 'o' && y != 'u') {
                    j--;
                } else {
                    break;
                }
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