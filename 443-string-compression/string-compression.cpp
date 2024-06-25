class Solution {
public:
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
};