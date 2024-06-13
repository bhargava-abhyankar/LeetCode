class Solution {
public:

    /* My first intution and solution 

    int strStr(string haystack, string needle) 
    {
        if(needle.length() > haystack.length()) {
            return -1;
        }

        int i = 0;

        while(i < haystack.length()) {
            int j = i, k = 0;
            while( j < haystack.length() && k < needle.length() && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if(k == needle.length()) {
                return i;
            }
            i++;
        }

        return -1;
    }

    */

    int strStr(string haystack, string needle) 
    {
        if(needle.length() > haystack.length()) {
            return -1;
        }

        int i = 0;

        while(i <= (haystack.length() - needle.length())) {
            int j = i, k = 0;
            while( j < haystack.length() && k < needle.length() && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if(k == needle.length()) {
                return i;
            }
            i++;
        }

        return -1;
    }

};