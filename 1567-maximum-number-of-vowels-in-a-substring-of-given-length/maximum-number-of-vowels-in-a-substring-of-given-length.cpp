class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int left = 0, right = 0, count = 0, ans = 0;

        while(right < s.length()) {
            if (right-left+1 <= k) {
                if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') {
                    count++;
                }
                right++;
            } else if (right-left+1 > k) {
                if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u') {
                    count++;
                }

                if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u') {
                    count--;
                }
                left++;
                right++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};