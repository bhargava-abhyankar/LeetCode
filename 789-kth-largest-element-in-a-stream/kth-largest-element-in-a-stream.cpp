class KthLargest {
public:

    /* Method 1: By maintaining sorted list.

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

    */


    /* Method 2: Using heap or min queue */

    int size;
    vector<int> stream; // this is just to maintain the order. there could be some followup so.
    priority_queue<int, vector<int>, greater<int>> min_heap;

    KthLargest(int k, vector<int>& nums) 
    {
        size = k;

        for(int i = 0; i < nums.size(); i++) {
            stream.push_back(nums[i]);
            add(nums[i]);
        }
    }
    
    int add(int val) 
    {
        if(min_heap.size() < size) {
            min_heap.push(val);
        } else {
            if(min_heap.top() < val) {
                min_heap.pop();
                min_heap.push(val);
            }
        }

        stream.push_back(val);
        return min_heap.top();
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */