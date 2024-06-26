class Solution {
public:

    /* Brute force: time complexity is o(n3). first two loops o(n2) and checking palindrome o(n) */

    /*
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

    */

    /* below code is same as above code, another format in which all combination can be printed. However adding one condition to this, can make 
       validation of palindrome optimized. while generating all combination itself we check if the addtion will lead to palindrome or not.
       for better understanding writen below code to check if all combination are generated. further below code is writen using this template
       for palindrome check */

    /*
    void print_combination(string s, int i, int j)
    {
        while(i >= 0 && j < s.length()) {
            for(int k = i; k <=j; k++) {
                cout << s[k];
            }
            i--;
            j++;
            cout<<endl;
        }
    }

    int countSubstrings(string s) 
    {
        for(int i = 0; i < s.length(); i++) {
            print_combination(s, i, i+1);
            print_combination(s, i, i);    
        }

        return 0;
    }

    */


    int is_valid_palindrome(string &s, int i, int j)
    {
        int count = 0;

        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
            count++;
        }

        return count;
    }

    int countSubstrings(string s)
    {
        int sum = 0;

        for(int i = 0; i < s.length(); i++) {
            int even = is_valid_palindrome(s, i, i+1);
            int odd = is_valid_palindrome(s, i, i);
            sum = sum + even + odd;
        }

        return sum;
    }

    /* This is actually dp problem, study dp solution, once u have started dp and do this problem */
};