class Solution {
public:

    int update_missing(vector<int>&missing, int i, int j, int &k)
    {
        for(int x = i + 1; x < j; x++) {
            cout << x << endl;
            missing.push_back(x);
            k--;

            if(k == 0) {
                return x;
            }
        }

        return -1;
    }

    int findKthPositive(vector<int>& arr, int k) 
    {
        int x, n = arr.size();
        vector<int>missing;

        if(arr[0] != 1) {
            x = update_missing(missing, 0, arr[0], k);

            if(x != -1) {
                return x;
            }
        }

        for(int i = 0; i < n-1 ; i++) {
            if((arr[i+1] - arr[i]) > 1) {
                x = update_missing(missing, arr[i], arr[i+1], k);

                if(x != -1) {
                    return x;
                }
            }
        }
        
        return (arr[n-1] + k);
    }
};