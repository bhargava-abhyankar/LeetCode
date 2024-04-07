class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        int level = 1;
        unordered_set <string> bank(wordList.begin(), wordList.end());
        unordered_set <string> is_vis;
        queue<string> q;

        if(bank.find(endWord) == bank.end()) {
            return 0;
        }

        q.push(beginWord);
        is_vis.insert(beginWord);

        while(!q.empty()) {
            int size =  q.size();

            for(int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();

                if(cur == endWord)
                    return level;

                for(int j = 0; j < cur.length(); j++) {
                    for(char ch : "abcdefghijklmnopqrstuvwxyz") {
                        if(cur[j] != ch) {
                            string adj =  cur;
                            adj[j] = ch;

                            if (bank.find(adj) != bank.end() && is_vis.find(adj) == is_vis.end()) {
                                is_vis.insert(adj);
                                q.push(adj);
                            }
                        }
                    }
                }
            }
            level++;
        }

        return 0;
    }
};