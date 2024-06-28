class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int i = 0;
        vector<vector<int>> ans;

        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {             // cur_maximun is less than new min. so lower bound
            ans.push_back(intervals[i]);
            i++;
        }

        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {          // break loop when cur_minimum is bigger than new maximum
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back({newInterval[0], newInterval[1]});

        while(i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};