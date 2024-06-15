class Solution {
public:

    void backtracking(unordered_map<char, string> &table, string digits, int cur_digit, string &ans, vector<string> &final_ans)
    {
        if(digits.length() == ans.length()) {
            final_ans.push_back(ans);
            return;
        }

        for(int i = cur_digit; i < digits.length(); i++) {
            char c = digits[i];
            string x = table[c];

            for(int j = 0; j < x.length(); j++) {
                ans.push_back(x[j]);
                backtracking(table, digits, i+1, ans, final_ans);
                ans.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        string cur_ans;
        vector<string> ans;

        if(digits.length() == 0) {
            return ans;
        }

        unordered_map<char, string> table;
        table.insert({'2', "abc"});
        table.insert({'3', "def"});
        table.insert({'4', "ghi"});
        table.insert({'5', "jkl"});
        table.insert({'6', "mno"});
        table.insert({'7', "pqrs"});
        table.insert({'8', "tuv"});
        table.insert({'9', "wxyz"});

        backtracking(table, digits, 0, cur_ans, ans);
        return ans;
    }
};