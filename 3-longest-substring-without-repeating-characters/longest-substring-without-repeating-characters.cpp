class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans = 0, i = 0, j = 0;
        unordered_set<char> hash;

        while(i < s.length()) {
            int count = 0;
            
            while(j < s.length() && hash.find(s[j]) == hash.end()) {
                hash.insert(s[j]);
                j++;
            }

            ans = max(ans, j - i);
            if(j < s.length()) {
                
                auto itr = hash.find(s[i]);

                if(itr != hash.end()) {
                    hash.erase(itr);
                }
            }
            i++;
        }
        return ans;
    }
};