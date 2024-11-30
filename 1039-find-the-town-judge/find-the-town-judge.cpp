class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> in_count(n+1, 0);
        vector<int> out_count(n+1, 0);

        for(int i = 0; i < trust.size(); i++) {
            int trusting = trust[i][0];
            int trusted = trust[i][1];

            out_count[trusting]++;
            in_count[trusted]++;
        }

        for(int i = 1; i <= n; i++) {
            if(in_count[i] == n-1 && out_count[i] == 0) {
                return i;
            }
        }

        return -1;
    }

};