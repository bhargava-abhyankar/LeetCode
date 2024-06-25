class Solution {
public:

    /*
    int compress(vector<char>& chars) 
    {
        int  j = 0, compressed_size = 0;

        while(j < chars.size()) {
            
            int count = 0;
            char ch = chars[j];

            while(j < chars.size() &&  ch == chars[j]) {
                count++;
                j++;
            }

            chars[compressed_size] = ch;
            compressed_size++;

            if(count > 1) {
                for(char &ch: to_string(count)) {
                    chars[compressed_size] = ch;
                    compressed_size = compressed_size + 1;
                }
            }
        }

        return compressed_size;
    }
    */

     /* Use three pointer. one to update the result after compression. for comparing if its a repeat use usual two pointer */

    int compress(vector<char>& chars) 
    {
        int i = 0, j = 0, compressed_length = 0;

        while(j < chars.size()) {
            int count = 0;
            i = j;

            while(j < chars.size() && chars[i] == chars[j]) {
                count++;
                j++;
            }

            chars[compressed_length] = chars[i];
            compressed_length++;

            if(count > 1) {
                for(char &ch: to_string(count)) {
                    chars[compressed_length] = ch;
                    compressed_length++;
                }
            }
        }

        return compressed_length;
    }

    /*use only two pointer, note how to find repeat with single pointer */




};