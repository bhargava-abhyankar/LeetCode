class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) 
    {
        int i = 0, j = 0;

        while(i < word.length() && j < abbr.length()) {
            if(word[i] == abbr[j]) {
                i++;
                j++;
                continue;
            } else {
                if(abbr[j] >= 48 && abbr[j] <= 57) {
                    int sum = 0;

                    if(abbr[j] == '0')
                        return false;

                    while((j < abbr.length()) && abbr[j] >= 48 && abbr[j] <= 57) {
                        sum = sum * 10 + (abbr[j] - 48);
                        j++;
                    }
                    i = i + sum;
                } else {
                    return false;
                }
            }
        }

        if(i == word.length() && j == abbr.length())
            return true;
        else
            return false;
        
    }
};