class Solution {
public:

    /* Idea is, for every meeting, we should check, what is first meeting that will be finishing. first meeting means the meeting with least end time. 
       if the current meeting is colliding with first finishing meeting, we need new room, so increase the meeting room count.
       if its not colliding then, we can use same room. just pop the last finished meeting and insert the current */
       
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return(a[0] < b[0]);
    }

    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        int ans = 1;

        if(intervals.size() < 2) {
            return 1;
        }

        
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int i = 1;
        pq.push({intervals[0][1], intervals[0][0]});

        while(i < intervals.size()) {

            auto least = pq.top();

            if(least.first > intervals[i][0] ) {
                ans = ans +1;
                pq.push({intervals[i][1], intervals[i][0]});
            } else {
                pq.pop();
                pq.push({intervals[i][1], intervals[i][0]});
            }

            i++;
        }
        return ans;
    }
};