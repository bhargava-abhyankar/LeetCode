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

    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        int nIndex = 0;
        for(int i=0; i<hLen; i++){
            // as long as the characters are equal, increment needleIndex
            if(haystack[i]==needle[nIndex]){
                nIndex++;
            }
            else{
                // start from the next index of previous start index
                i=i-nIndex;
                // needle should start from index 0
                nIndex=0;
            }
            // check if needleIndex reached needle length
            if(nIndex==nLen){
                // return the first index
                return i-nLen+1;
            }
        }
        return -1;
    }
};