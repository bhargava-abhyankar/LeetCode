class Solution {
public:
    
    /* method 1 : Brute force 

    void generate_all_combinations(string &num, string cur, int index, vector<string> &all_combinations,
                                    int k)
    {
        if(k == 0) {
            all_combinations.push_back(cur);
            return;
        }

        for(int i = index; i < num.length(); i++) {
            cur = cur + num[i];
            generate_all_combinations(num, cur, i +1, all_combinations, k-1);
            cur.pop_back();    
        }
    }

    string removeKdigits(string num, int k) 
    {
        vector<string> all_combinations;
        string cur;
        generate_all_combinations(num, cur, 0, all_combinations, num.length()- k);

        string smallest = "";

        for(int i = 0; i < all_combinations.size(); i++) {
            string candidate = all_combinations[i];
                        
            if(smallest == "" || candidate < smallest) {

                while(candidate.length() > 0 && candidate[0] == '0') {
                    candidate.erase(candidate.begin());
                }

                smallest = candidate;
            }
        }

        return smallest == "" ? "0":smallest;
    }

    */

    /* Method 2: Using stack */

    string removeKdigits(string num, int k) 
    {
        string ans;

        for(int i = 0; i < num.length(); i++) {

            while(ans.size() > 0 && k > 0 && ans[ans.size() -1] > num[i]) {
                ans.pop_back();
                k--;
            }

            ans.push_back(num[i]);
        }

        /* remove the remaining digits from the tail. */

        for(int i = 0; i < k; i++) {
            ans.pop_back();
        }

        while(ans.length() > 0 && ans[0] == '0') {
            ans.erase(ans.begin());
        }

        return ans.length() == 0 ? "0": ans;
    }

};