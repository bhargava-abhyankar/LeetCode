class Solution {
public:

    /* Initial intution.

    static bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[0] < b[0]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size() < 2) {
            return intervals;
        }

        int i = 0, j = 0;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), comp);

        while(i < intervals.size()) {
            j = i + 1;
            while((j < intervals.size()) && (intervals[i][0] <= intervals[j][0]) && (intervals[i][1] >= intervals[j][0])) {
                j++;
            }

            ans.push_back({intervals[i][0], max(intervals[i][1], intervals[j-1][1])});
            i = j;
        }

        return ans;
    }
    */


    /* The issue in the provided code lies in the condition used to merge the intervals within the nested while loop. 
       Specifically, the condition (intervals[i][0] <= intervals[j][0]) && (intervals[i][1] >= intervals[j][0]) is incorrect because it only checks 
       for overlapping intervals based on the start and end of the current interval. It should instead check if the start of the next interval is less 
       than or equal to the end of the current interval.
     */


    static bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[0] < b[0]);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size() < 2) {
            return intervals;
        }

        int i = 0, j = 0;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), comp);

        while(i < intervals.size()) {
            j = i + 1;

            int start = intervals[i][0];
            int end = intervals[i][1];

            while((j < intervals.size()) && (end >= intervals[j][0])) {
                end = max(end, intervals[j][1]);
                j++;
            }

            ans.push_back({start, end});
            i = j;
        }

        return ans;
    }
};