class Solution {
public:

    /*Approach :
        We need to find overlapping intervals or the intersection. u should not find union. why .. see below pick

        1 ---------------------------6
                2--------------------------------8
                                            7---------------------12
                                                        10-----------------------------16
        if u hit at 2, 2 ballons will go (first and second), if u hit at 6 also 2 ballons will go ((first and second)), 
        if hit at 7, then also 2 ballons will go but ballon 2 and 3 will go. there is no away in single shot 3 ballons will go
        since they three do not overlap. only 2 overlap. thats why we need to find overlap interval and merge, instead of finding
        union. if u find union, all will get merge and it becomes 1 16. and u will think u need only one ballon to burst all. which
        is wrong                         
    */


    static bool comp(vector<int> &a, vector<int> &b)
    {
        return(a[0] < b[0]);
    }

    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), comp);

        int i = 0, j = 0, count = points.size();

        while(i < points.size()) {
            j = i + 1;

            while(j < points.size() && points[i][1] >= points[j][0]) {          
                points[i][1] = min(points[i][1], points[j][1]);                 // this is how u find overlapping interval. if u do max of it, then u will find union of it. here its intersection
                j++;
                count--;
            }
            i = j;
        }
        return count;
    }
};