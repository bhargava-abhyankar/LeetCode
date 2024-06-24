class Solution {
public:

    int next_number(int n)
    {
        int sum = 0;

        while(n) {
            int t = n % 10;
            sum = sum + (t * t);
            n = n/10;
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        unordered_set<int> hash;

        while(n != 1) {
            if(hash.find(n) == hash.end()) {
                hash.insert(n);
                n = next_number(n);
            } else {
                return false;
            }
        }

        return true; 
    }
};