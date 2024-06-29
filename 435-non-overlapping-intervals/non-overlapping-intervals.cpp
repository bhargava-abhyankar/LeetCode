class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b)
    {
        return(a[1] < b[1]);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), comp);

        int i = 0, j = 1, count = 0;

        while(i < intervals.size()) {
            j = i + 1;

            while(j < intervals.size() && intervals[i][1] > intervals[j][0]) {
                j++;
                count++;
            }
            i = j;
        }
        return count;
    }
};