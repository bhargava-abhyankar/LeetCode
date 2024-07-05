class Solution {
public:

    /* Simple two pointer works. Because we just have to find the number of children. Also no matter what is the size of the cookie, it can be given to only 
       one child. Just check if it satisfies the greed or not, if not go for higher number, if satisfies go for next child with next cookie.
       Both children and cokies need to be sorted for this to work. so nlogn*/

    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, count = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                count = count + 1;
                j++;
                i++;
            } else {
                j++;
            }
        }

        return count;        
    }
};