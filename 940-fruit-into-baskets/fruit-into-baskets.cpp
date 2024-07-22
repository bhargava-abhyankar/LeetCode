class Solution {
public:

    /* first intution. dint work because of this case. [3,3,3,1,2,1,1,2,3,3,4]
    
    int totalFruit(vector<int>& fruits) 
    {
        unordered_set<int> hash;

        int left = 0, right = 0, ans = 0;

        while(right < fruits.size()) {

            if(hash.find(fruits[right]) == hash.end()) {
                hash.insert(fruits[right]);
                right++;

                if(hash.size() > 2) {
                    auto itr = hash.find(fruits[left]);
                    hash.erase(itr);
                    left++;
                }
            } else {
                right++;
            }
            ans = max(ans, right-left);
        }

        return ans;
    }

    */

    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int, int> hash;
        int left = 0, right = 0, ans = 0;

        while(right < fruits.size()) {
            hash[fruits[right]]++;
            right++;

            if(hash.size() > 2) {
                hash[fruits[left]]--;
                if(hash[fruits[left]] == 0) {
                    hash.erase(hash.find(fruits[left]));
                }
                left++;
            }
            ans = max(ans, right-left);
        }

        return ans;
    }
};