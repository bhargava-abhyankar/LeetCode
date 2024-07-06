class Solution {
public:

    /* First intution, this becomes tricky. actually there is need to handle so much. check solution

    int romanToInt(string s) 
    {
        unordered_map<char, int> hash = { {'I', 1},
                                          {'V', 5},
                                          {'X', 10},
                                          {'L', 50},
                                          {'C', 100},
                                          {'D', 500},
                                          {'M', 1000}};

        int sum = 0, temp = 0, i = 0, j = 1, n = s.length()-1;

        for( i = 0, j = 1; i < s.length() && j < s.length(); i++, j++) {
            int i_ = hash[s[i]];
            int j_ = hash[s[j]];
            
            if (i_ > j_)  {
                sum = sum + temp + i_;
                temp = 0;

            } else if (i_ == j_) {
                temp = temp + i_;

            } else if (i_ < j_) {
                sum = sum + (j_ - temp - i_);
                temp = 0;
                i = j;
            }
            cout << sum << endl;
        }

        if(i < j) {
            sum = sum + temp + hash[s[n]];
        }


        return sum;
    }
    */

    /*Simple math: start from 0 to n-1. compare every element with next, except last. if cur num is less than next. subtract it from existing sum.
      if equal or greater them add. Last element, has no next element. just add check to see if its last element, if yes then just add it to sum */

    int romanToInt(string s) 
    {
        unordered_map<char, int> hash = { {'I', 1},
                                          {'V', 5},
                                          {'X', 10},
                                          {'L', 50},
                                          {'C', 100},
                                          {'D', 500},
                                          {'M', 1000}};

        int sum = 0, temp = 0, i = 0, j = 1, n = s.length()-1;

        for( i = 0, j = 1; i < s.length(); i++, j++) {

            if(i == s.length()-1) {
                sum = sum + hash[s[i]];
                continue;
            }

            int i_ = hash[s[i]];
            int j_ = hash[s[i+1]];

            if(i_ < j_) {
                sum = sum - i_;
            } else {
                sum = sum + i_;
            }
        }
        return sum;
    }
};