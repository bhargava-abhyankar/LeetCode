class Solution {
public:

    /* Typical binary search or modified binary search. will not work. Due to fact that, if 
       the element is not present, then there is no surity where the binary search stop happens
       with respect to closeness of the target.
       
       Binary Search: It focuses on comparing the target element directly with the mid element to decide 
       the search direction.
       This Problem: We need to compare distances |arr[mid] - x|, |arr[mid-1] - x|, and |arr[mid+1] - x| 
       to ensure we select the closest elements.

    */

    /*
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int> ans;
        int start = 0, end = arr.size()-1;

        while(start < end) {
            int mid = (start + end) / 2;

            if(arr[mid] < x) {
                start = mid+1;
            } else {
                end = mid;
            }
        }

        cout << start << endl;

        if(start == 0) {
            for(int i = 0; i < k; i++) {
                ans.push_back(arr[i]);
            }
            return ans;

        } else if (start == arr.size()-1) {
            for(int i = arr.size()-1; k > 0; i--, k--) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        int p1 = start, p2 = start + 1;

        while(p1 >= 0 && p2 <= arr.size()-1 && k) {
            if(abs(x - arr[p1]) < abs(x-arr[p2])) {
                ans.push_back(arr[p1]);
                p1--;
            } else if (abs(x - arr[p1]) > abs(x-arr[p2])) {
                ans.push_back(arr[p2]);
                p2++;
            } else {
                ans.push_back(arr[p1]);
                p1--; 
            }
            k--;
        }

        while(k > 0 && p1 >= 0) {
            ans.push_back(arr[p1]);
            p1--;
            k--;
        }
        while (k > 0 && p2 <= arr.size()-1) {
            ans.push_back(arr[p2]);
            p2++;
            k--;
        }

        sort(ans.begin(), ans.end());               
        return ans;   
    }
    */

    /* Binary search somehow made possible, the issue with above code is addressed.
       after binary search checking the real close element to target */
    /*  
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int n=arr.size();
        int l=0,h=n-1,mid=0;
        // binary search part for getting closest to the element x
        while(l<=h)
        {
            mid=(l+h)/2;
            if(arr[mid]==x)
                break;
            else if(x<arr[mid])
                h=mid-1;
            else
                l=mid+1;
        }

        // this confirms the actual closest element from x
        // if the diff is coming same, then we are giving priority to left elements, as in sorted 
        // order they come first.

        int index=mid;
        if(mid-1>=0 && (abs(arr[mid-1]-x)<=abs(arr[index]-x)))
            index=mid-1;
        if(mid+1<n && (abs(arr[mid+1]-x)<abs(arr[index]-x)))
            index=mid+1;
       
        // this is taken from merging two sorted array algorithm.
        // selecting the closest index and setting the pointers to its right=j and left=i
        // and then traversing i to the left and j to the right based on their sorted values
        // k times, at the last sort the ans vector and return that
        int i=index-1;
        int j=index+1;
        vector<int>answer;
        answer.push_back(arr[index]);
        k--;
        while(k>0 && i>=0 && j<n)
        {
            if(abs(arr[i]-x)<=abs(arr[j]-x))  // here also giving more priority to i than j.
            {
                answer.push_back(arr[i]);
                k--;
                i--;    // moving i to the left
            }
            else
            {
                answer.push_back(arr[j]);
                k--;
                j++;  // moving j to the right
            }
        }
        while(i>=0 && k>0)
        {
            answer.push_back(arr[i]);
            k--;
            i--;
        }
        while(j<n && k>0)
        {
            answer.push_back(arr[j]);
            k--;
            j++;
        }

        // merge part ends here
	  
        sort(answer.begin(),answer.end()); // sorting the answer vector before returning
        return answer;
    }
    */

    /*
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,h=arr.size()-1;
        while((h-l)>=k){
            if(x-arr[l]>arr[h]-x)
            l++;
            else
            h--;
        }
        return vector<int>(arr.begin()+l,arr.begin()+h+1);
    }

    */




    /* Two pointer method. this is from solution section */

    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int> ans;

        int i = 0, j = arr.size()-1;

        while((j-i) >= k) {
            if( abs(arr[i] - x) > abs(arr[j] - x)) {
                i++;
            } else {
                j--;
            }
        }

        for(int x = i; k > 0; k--, x++) {
            ans.push_back(arr[x]);
        }
        return ans;
    }
    
};