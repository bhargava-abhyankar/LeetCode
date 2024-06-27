class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b)
    {
        return(a[0] < b[0]);
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) 
    {
        if(intervals.size() < 2) {
            return true;
        }

        bool ans = true;
    
        sort(intervals.begin(), intervals.end(), comp);

        for(int i = 1; i < intervals.size(); i++) {
            int cur_start = intervals[i][0];
            int cur_end = intervals[i][1];
            int prev_start = intervals[i-1][0];
            int prev_end = intervals[i-1][1];

            if (!((cur_start >= prev_start) && (cur_start >= prev_end) && (cur_end >= prev_start ) && (cur_end >= prev_end))) {
                return false;
            } 
        }

        return ans;
    }
};