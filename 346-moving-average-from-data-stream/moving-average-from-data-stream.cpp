class MovingAverage {
public:

    int capacity;
    queue<int> q;
    double cur_sum;

    MovingAverage(int size) {
        capacity = size;
        cur_sum = 0;
    }
    
    double next(int val) {
        if(q.size() < capacity) {
            cur_sum = cur_sum + val;
            q.push(val);    
        } else {
            cur_sum = cur_sum - q.front();
            cur_sum = cur_sum + val;
            q.pop();
            q.push(val);
        }

        return (cur_sum)/((double) q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */