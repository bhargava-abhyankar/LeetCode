class StockSpanner {
public:

    /*Brute force */

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
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */