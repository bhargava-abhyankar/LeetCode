class Solution {
public:

    /*First intution, wrong. this is not similar to longest non repeating charecter substring problem. this is
      fixed window len proble

    int countGoodSubstrings(string s) 
    {
        int ans = 0;
        unordered_set<char> hash;
        int i = 0, j = 0;

        while(i < s.length()) {
            while(j < s.length() && (hash.find(s[j]) == hash.end())) {
                hash.insert(s[j]);
                j++;
            }

            if((j - i) == 3)
                ans++;

            if(j < s.length()) 
            {
                auto itr = hash.find(s[i]);
                hash.erase(itr);
            }
            i++;

        }

        return ans;
    }
    */

    int countGoodSubstrings(string s) 
    {
        int ans = 0;
        int i = 0, j = 0, n = s.length();
        unordered_map<char, int> hash;

        while(i < n && j < n) {

            if (hash.find(s[j]) == hash.end()) {
                hash.insert({s[j], 1});
            } else {
                hash[s[j]] = hash[s[j]] + 1;
            }

            if((j-i+1) < 3) {
                j++;
            } else if(hash.size() == 3) {
                ans++;

                auto itr = hash.find(s[i]);
                hash[s[i]] = hash[s[i]] - 1;

                if(hash[s[i]] == 0) {
                    hash.erase(itr);
                }

                j++;
                i++;

            } else {
                auto itr = hash.find(s[i]);
                hash[s[i]] = hash[s[i]] - 1;

                if(hash[s[i]] == 0) {
                    hash.erase(itr);
                }
                i++;
                j++;
            }
        }

        return ans;
    }

};