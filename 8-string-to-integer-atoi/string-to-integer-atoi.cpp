class Solution {
public:

    /*First approach was done with intution. due to lot of negative cases, could not make this logic to work
      Dont take this complex approach. Simple approach is, first iterate and look for white spaces and skip them
      now u are first valid position, in whole string, + , - sign can come at begining only. check for it, if there
      is note it increment index. no sign may be there.. dont update index. now check until the string is numeric and
      compute value */


    /*
    int myAtoi(string s) 
    {
        long long int sum = 0;
        long long place_of_decimal = 1;
        int j = 0;

        for(j = 0; j < s.length(); j++) {
            if(s[j] == 48 || s[j] == ' ') {
                continue;
            } else if ( j != 0 && (s[j] == '+' || s[j] == '-') && s[j-1] == 48) {
                return 0;
            } else if ((s[j] > 48 && s[j] <=57) || s[j] == '+' || s[j] == '-') {
                break;
            } else {
                return 0;
            }
        }

        for(int i = s.length(); i >=j; i--) {
            if(s[i] >= 48 && s[i] <=57) {
                sum = sum + ((place_of_decimal) * (s[i] - 48));
                place_of_decimal = place_of_decimal * 10;
            } else if (s[i] == ' ' || s[i] == '+') {
                continue;
            } else if (s[i] == '-') {
                sum = -sum;
            } else {
                sum = 0;
                place_of_decimal = 1;
            }
        }

        if(sum > INT_MAX) {
            sum = INT_MAX;
        } else if (sum < INT_MIN) {
            sum = INT_MIN;
        }

        return ((int) sum);
    }
    */


    int myAtoi(string s) 
    {
        int i = 0;
        double sum = 0;
        bool is_positive = false, is_negative = false;

        while(i < s.length() && (s[i] == ' ')) {
            i++;
        }

        if(i < s.length() && s[i] == '+') {
            is_positive = true;
            
        }

        if(i < s.length() && s[i] == '-') {
            is_negative = true;
        }

        if(is_positive || is_negative)
            i++;

        while(i < s.length() && (s[i] >= 48 && s[i] <= 57)) {
            sum = (sum * 10) + (s[i] - 48);
            i++;
            cout << i << endl;
        }

        if(is_negative) {
            sum = -sum;
        }

        if(sum < INT_MIN) {
            return INT_MIN;
        } else if (sum > INT_MAX) {
            return INT_MAX;
        } else { 
            return (int)sum;
        }
    }

};