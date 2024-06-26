class Solution {
public:

    /* Brute force: time complexity is o(n3). first two loops o(n2) and checking palindrome o(n) */


    int is_palindrome(int i, int j, string s)
    {
        while(i <= j) {
            if(s[i] != s[j]) {
                return 0;
            }
            i++;
            j--;
        }

        return 1;
    }

    int countSubstrings(string s) 
    {
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                sum = sum + is_palindrome(i, j, s);
            }
        }

        return sum;
    }

    /* This is dp problem */
};