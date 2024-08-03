class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_set<string> supply_table;
        queue<string> q;
        vector<string> ans;

        for(int i = 0; i < supplies.size(); i++) {
            supply_table.insert(supplies[i]);
        }

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;

        for(int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = 0;
        }

        for(int i = 0; i < recipes.size(); i++) {
            for(int j = 0; j < ingredients[i].size(); j++) {

                if(supply_table.find(ingredients[i][j]) == supply_table.end()) {
                    adj[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        for(auto x: indegree) {
            if(x.second == 0) {
                q.push(x.first);
            }
        }

        while(!q.empty()) {
            string cur = q.front();
            ans.push_back(cur);
            q.pop();

            for(int i = 0; i < adj[cur].size(); i++) {
                string neighbor = adj[cur][i];
                indegree[neighbor]--;

                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;

    }
};