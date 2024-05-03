class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        int level = 0;
        unordered_set<string> restricted;
        queue<string> q;
        
        for(int i = 0; i < deadends.size(); i++) {            
            restricted.insert(deadends[i]);
        }

        if(restricted.find("0000") != restricted.end()) {
            return -1;
        }
        
        q.push("0000");
        restricted.insert("0000");

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();

                if(cur == target) {
                    return level;
                }

                for(int j = 0; j < 4; j++) {
                    char ch = cur[j];

                    cur[j] == '9' ? cur[j] = '0' : cur[j] = cur[j] + 1;

                    if(restricted.find(cur) == restricted.end()) {
                        q.push(cur);
                        restricted.insert(cur);
                    }

                    cur[j] = ch;
                    
                    cur[j] == '0' ? cur[j] = '9' : cur[j] = cur[j] - 1;

                    if(restricted.find(cur) == restricted.end()) {
                        q.push(cur);
                        restricted.insert(cur);
                    }

                    cur[j] = ch;
                }
            }
            level++;
        }

        return -1;
    }
};