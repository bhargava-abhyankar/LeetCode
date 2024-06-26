class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string ans;
        int i = 0, j = 0;

        while((i < word1.length()) && (j < word2.length())) {
            ans.push_back(word1[i]);
            i++;
            ans.push_back(word2[j]);
            j++;
        }

        while(i < word1.length()) {
            ans.push_back(word1[i]);
            i++;
        }

        while(j < word2.length()) {
            ans.push_back(word2[j]);
            j++;
        }

        return ans;
    }
};