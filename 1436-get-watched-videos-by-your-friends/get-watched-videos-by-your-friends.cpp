class Solution {
public:

    /* First Do BFS, so that u reach the required level. once you have reached, queue will have friends. pop them one by one
       for each friend, go through their video list and increment count for the that video. then sort it based on count, then
       fill ans array in ascending order */

    /*
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        int n = watchedVideos.size();
        vector<bool> is_vis(n, false);
        unordered_map<string, int> hmap;
        vector<string> ans;
        vector<int> res;

        queue<int> q;
        int cur_level = 1;
        q.push(id);
        is_vis[id] = true;

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {
                int cur_node = q.front();
                q.pop();

                for(int j = 0; j < friends[cur_node].size(); j++) {
                    int x = friends[cur_node][j];

                    if(is_vis[x] == false) {
                        is_vis[x] = true;
                        if(cur_level == level) {
                            res.push_back(x);
                        } else {
                            q.push(x);
                        }                      
                    }
                }
            }
            cur_level++;
        }

        for(int i = 0; i < res.size(); i++) {
            int y = res[i];

            for(int j = 0; j < watchedVideos[y].size(); j++) {
                string s = watchedVideos[y][j];
                hmap[s]++;
            }
        }

        vector<pair<int, string>> to_sort;

        for(auto i: hmap) {
            to_sort.push_back({i.second, i.first});
        }

        sort(to_sort.begin(), to_sort.end());

        for(auto itr: to_sort) {
            ans.push_back(itr.second);
        }

        return ans;
    }
    */

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        vector<bool> is_vis(friends.size(), false);
        unordered_map<string, int> hmap;
        vector<string> ans;

        queue<int> q;
        int cur_level = 0;
        q.push(id);
		is_vis[id] = true;
		
        while(!q.empty()) {
            int size = q.size();

            if(cur_level == level) {                  
                break;
            }

            for(int i = 0; i < size; i++) {
                int cur_node = q.front();
                q.pop();

                for(int j = 0; j < friends[cur_node].size(); j++) {
                    int x = friends[cur_node][j];

                    if(is_vis[x] == false) {
						is_vis[x] = true;
                        q.push(x);                      
                    }
                }
            }

            cur_level++;
        }

        while(!q.empty()) {
            int y = q.front();
            q.pop();

            for(int i = 0; i < watchedVideos[y].size(); i++) {
                string s = watchedVideos[y][i];
                hmap[s]++;
            }
        }

        vector<pair<int, string>> to_sort;

        for(auto i: hmap) {
            to_sort.push_back({i.second, i.first});
        } 

        sort(to_sort.begin(), to_sort.end());

        for(auto itr: to_sort) {
            ans.push_back(itr.second);
        }

        return ans;
    }

};