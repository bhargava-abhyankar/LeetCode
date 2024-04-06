class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        int level = 0;
        unordered_set<string>adj(bank.begin(), bank.end());
        unordered_set<string>is_vis;
        queue<string> q;

        if(adj.find(endGene) == adj.end()) {
            return -1;
        }

        q.push(startGene);
        is_vis.insert(startGene);

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();

                if(endGene == cur) {
                    return level;
                }

                for(int j = 0; j < cur.length(); j++) {
                    for(char ch : "ACGT") {
                        if(cur[j] != ch) {
                            string mutate = cur;
                            mutate[j] = ch;

                            if(is_vis.find(mutate) == is_vis.end() && adj.find(mutate) != adj.end()) {
                                is_vis.insert(mutate);
                                q.push(mutate);
                            }
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};