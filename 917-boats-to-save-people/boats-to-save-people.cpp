class Solution {
public:

    /* First approach does not work because of the duplicate element. using map, will not be able to handle duplicate case 
        simple two pointer will solve */
        
    /*
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int count = 0;
        unordered_map<int, int> ht;

        for(int i = 0; i < people.size(); i++) {
            if ((limit - people[i]) == 0) {
                count++;
            } else if ((ht.find(limit - people[i])) != ht.end()) {
                ht.erase(limit - people[i]);
                count++;
            } else {
                ht.insert({people[i], i});
            }
        }
        count = count + ht.size();
        return count;
    }
    */

    int numRescueBoats(vector<int>& people, int limit) 
    {
        int ans = 0;
        int i = 0, j = people.size()-1;

        sort(people.begin(), people.end());

        while(i <= j) {
            int cur_size = people[i] + people[j];

            if(cur_size <= limit) {
                i++;
                j--;
            } else  {
                j--;
            }
            ans++;
        }

        return ans;
    }

};