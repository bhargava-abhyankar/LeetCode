class Solution {
public:

    /*

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

    */

    /* Method 1: Sliding window */

    int lengthOfLongestSubstring(string s) 
    {
        int max_length = 0;
        unordered_set<char> hash;
        
        int start = 0;

        for(int end = 0; end < s.size(); end++) {
            while(hash.find(s[end]) != hash.end()) {
                hash.erase(s[start]);
                start++;
            }
            hash.insert(s[end]);
            max_length = max(max_length, end - start + 1);
        }

        return max_length;
    }
};