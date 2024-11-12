class StockSpanner {
public:

    /* Brute force

    vector<int> ans;

    StockSpanner() {
        
    }
    
    int next(int price) 
    {
        int j = 0;
        ans.push_back(price);

        for(int i = ans.size()-1; i >= 0 && ans[i] <= price ; i--) {
            j++;
        }
        return j;
    }

    */

    /* Method 1: Monotonic stack */

    stack<pair<int, int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) 
    {
        int ans = 1;

        while(!st.empty() && st.top().first <= price) {
            ans = ans + st.top().second;
            st.pop();
        }

        st.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */