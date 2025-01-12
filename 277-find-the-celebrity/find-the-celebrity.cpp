/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {

    
public:

    /* Method 1: Using brute force */

    bool is_celebrity(int candidate, int n)
    {
        for(int i = 0; i <n; i++) {
            if(i == candidate) {
                continue;
            }

            if(knows(candidate, i) || !knows(i, candidate))
                return false;
        }

        return true;
    }

    int findCelebrity(int n) 
    {
        for(int i = 0; i < n; i++) {
            if(is_celebrity(i, n)) {
                return i;
            }
        }
        return -1;
    }


    /*  Method 2: 
    
        knows(int a, int b) has two outcomes:
        true: a knows b, so a is not celebrity, b is the candidate
        false: a doesn't know b, so b can't be the celebrity, then a is the candidate.
        By calling API n - 1 times, each call we pick one and drop the other one, so in the end, we have one candidate left. 
        Then we do another pass to check if everyone else know the candidate, and the candidate knows nobody else.
    
        This approach will do within 3*n knows calls

    int findCelebrity(int n) 
    {
        int candidate = 0;      //taking first element

        for(int i = 1; i < n; i++) {
          
            if(knows(candidate, i)) {      
                candidate = i;
            } 
        }

        cout << candidate << endl;

        for(int i = 0; i < n; i++) {
            if(candidate == i) {
                continue;
            }

            if(knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }

        return candidate;  
    }

    */
};