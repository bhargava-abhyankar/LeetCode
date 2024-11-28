class KthLargest {
public:

    /* Method 1: By maintaining sorted list */

    int size;
    vector<int> stream;

    KthLargest(int k, vector<int>& nums) 
    {
        size = k;

        for(int i = 0; i < nums.size(); i++) {
            stream.push_back(nums[i]);
        }
        sort(stream.begin(), stream.end());
    }
    
    int add(int val) 
    {
        int index = get_index(val);

        stream.insert(stream.begin() + index, val);
        return stream[stream.size() - size];
    }

    int get_index(int key)
    {
        int start = 0, end = stream.size()-1;

        while(start <= end) {
            int mid = (start + end) / 2;

            if(stream[mid] == key) {
                return mid;
            } else if(stream[mid] < key) {
                start = mid + 1;
            } else {
                end = mid -1;
            }
        }

        return start;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */