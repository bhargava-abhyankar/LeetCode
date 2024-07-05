class Solution {
public:

    /*Initial thought was something like, spliting the pattern and query for Capital_all_small .. Capital_all_small .. then for both query and pattern just extract
      Capital letter .. All capital should match. All splits string of patter should be there in query then match etc .. too tedius .. not at all required 
      
      
      Simple 2 pointers. Traverse both. If both match increment both. if doesnt match, check if query has small letter .. if small latter then move on, if dint match
      not small letter, false it is. Once loop breaks, if both are over.. well and good .. true, if not
      check if pattern is over , if not over then false. If pattern over, but query over, remaining all should be small
      if not false. */

    bool compute(vector<string>& queries, string pattern, int q)
    {
        int i = 0, j = 0;

        while(i < queries[q].length() && j < pattern.length()) {
            if(queries[q][i] == pattern[j] ) {
                i++;
                j++;
            } else if (queries[q][i] >= 'a' && queries[q][i] <= 'z') {
                i++;
            } else {
                return false;
            }
        }
        
        if(j < pattern.length()) {
            return (false);
        }

        while(i < queries[q].length()) {

            if(queries[q][i] >= 'a' && queries[q][i] <= 'z') {
                i++;
            } else {
                return(false);
            }
        }

        return true;
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) 
    {
        vector<bool> ans;

        for(int q = 0; q < queries.size(); q++) {
            ans.push_back(compute(queries, pattern, q));
        }
        
        return ans;
    }
};