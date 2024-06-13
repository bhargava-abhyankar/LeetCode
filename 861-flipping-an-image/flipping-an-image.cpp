class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
    {
        for(int i = 0; i < image.size(); i++) {
            int start = 0, end = image[0].size()-1;

            while(start < end) {
                int x = (!(image[i][start]));
                int y =  (!(image[i][end]));
                
                image[i][start] = y;
                image[i][end] = x;
                start++;
                end--;
            }
            if(start == end) {
               image[i][start] = !(image[i][start]); 
            } 
            
        }

        return image;
    }
};