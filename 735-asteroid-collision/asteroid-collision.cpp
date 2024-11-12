class Solution {
public:

    /* Method 1: Using stack 
    
        Lets consider an example:- [8, 9, 6, -7, -9, 12, 50, -34]
        Start iterating from the beginning. Whenever we encounter a positive value, 
        we don't have to do anything. Since they are fixed, they won't attack anyone. But the moment 
        we sees a negative value, we are sure it is going to attack positive values.

        Imagine [8, 9, 6] are happily sitting inside the array. The moment -7 enters, it will start 
        knocking out positive values. This gives an idea we can use a stack to solve this problem.

        Explanation

        Lets see how to use this idea to code. Consider the same example [8, 9, 6, -7, -9, 12, 50, -34]
        Initially i = 0. Whenever we encounter a positive value, we will simply push it to the stack.
        The moment we encounter a negative value, we know some or all or zero positive values will be 
        knocked out of the stack. The negative value may itself be knocked out or it may enter the stack.
        We will keep on poping the elements from the stack while the asteroids[i] > s.top(). But remember, 
        negative asteroids can never pop another negative asteroids, since they will never meet them. 
        So, the final condition is while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])), 
        we will pop the elements.
        We have to take care of the case when s.top() == asteroids[i]. In this case one positive element 
        will pop out and negative asteroid won't enter the stack.
        If after knocking out elements stack becomes empty() or s.top() becomes negative, 
        that means the current asteroids[i] will enter the stack. 

    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++) {

            if(st.empty() || asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }

                if(!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();
                } else {
                    if(st.empty() || st.top() < 0) {
                        st.push(asteroids[i]);
                    }
                }
            }
        }

        vector<int> ans(st.size(), 0);

        for(int i = ans.size()-1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }

    */

    /* Two pointer/ in place replacement. Same above logic just using given array as stack */

    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int j = 0;

        for(int i = 0; i < asteroids.size(); i++) {

            if(j == 0 || asteroids[i] > 0) {
                asteroids[j] = asteroids[i];
                j++;
            } else {

                while(j > 0 && asteroids[j-1] > 0 && asteroids[j-1] < abs(asteroids[i])) {
                    j--;
                }

                if(j > 0 && asteroids[j-1] == abs(asteroids[i])) {
                    j--;
                } else {
                    if(j == 0 || asteroids[j-1] < 0) {
                        asteroids[j] = asteroids[i];
                        j++;    
                    }
                }
            }
        }

        vector<int> result(asteroids.begin(), asteroids.begin() + j);
        return result;
    }

};