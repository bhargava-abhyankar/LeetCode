class Solution {
public:

    string repeatLimitedString(string s, int repeatLimit) 
    {
        string ans;
        vector<int> hash(26, 0);
        priority_queue<pair<char, int>> max_queue;

        for(int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            hash[index]++;
        }
    
        for (int i = 0; i < 26; i++) {
            if (hash[i] > 0) {
                max_queue.push({i + 'a', hash[i]});
            }
        }

        while(!max_queue.empty()) {
            int cur_freq = max_queue.top().second;
            char cur_char = max_queue.top().first;
            max_queue.pop();

            int count = min(cur_freq, repeatLimit);
            ans.append(count, cur_char);
            cur_freq -= count;
            
            if(cur_freq > 0) {
                if(max_queue.empty())
                    break;
            
                char next_char = max_queue.top().first;
                int next_char_freq = max_queue.top().second;
                max_queue.pop();

                ans += next_char;
                next_char_freq--;

                if(next_char_freq > 0)
                    max_queue.push({next_char, next_char_freq});

                max_queue.push({cur_char, cur_freq});
            }
        }

        return ans;
    }

};