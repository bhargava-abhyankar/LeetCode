class Solution {
public:

    /*
    method 1: using hash table. compute the number until one of earlier number is repeated or number has reached 1. every time after compute, put the number to hash table.
    if we have reached a number that was already reached before. then its a loop and number is not happy number.

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
    */

    /*method 2 : same principle. but instead of using hash table, using fast and slow pointer. if they meet, then there is a loop and the number is not happy. 
                 note that in happy number case, fast will reach 1 and keep repeating itself while slow is coming towards it. with if check, break is necessary.
                 because fast and slow will become 1 before n. so add break if fast and slow match. not return */

    int next_number(int n)
    {
        int sum = 0;

        while(n) {
            int t = n % 10;
            sum = sum + (t*t);
            n = n/10;
        }

        return sum;
    }

    bool isHappy(int n) 
    {
        int slow = n, fast = n;

        while(n != 1) {
            slow = next_number(slow);
            fast = next_number(next_number(fast));

            if(fast == slow) {
                break;
            }

            n = slow;
        }

        return (slow == 1 ? true:false);
    }
};