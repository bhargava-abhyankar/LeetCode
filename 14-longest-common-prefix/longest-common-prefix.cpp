class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        bool flag = false;
        string ans;

        for(int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            cout << ch << endl;

            for(int j = 1; j < strs.size(); j++) {
                if(ch != strs[j][i]) {
                    flag = true;
                    break;
                }
            }

            if(flag == true) {
                return ans;
            }
            
            ans.push_back(ch);
        }

        return ans;
    }
};