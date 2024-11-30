class Solution {
public:
    
    struct comparator {
        bool operator()(vector<int> const&a, vector<int> const&b)
        {
            return a[1] > b[1];
        }
    };


    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), comparator());

        for(int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
            if (boxTypes[i][0] <= truckSize) {
                truckSize = truckSize - boxTypes[i][0];
                ans = ans + boxTypes[i][0] * boxTypes[i][1];
            } else {
                ans = ans + truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }

        return ans;
    }
};