class MedianFinder {
public:

    /*My Initial intution. This is completetly wrong because median is found on sorted stream. I had assumed median directly on input. 
      Thats why had taken linked list and maintained a middle pointer to it.

    struct ListNode {
        double val;
        ListNode *next;
        ListNode(): val(0), next(NULL) {}
        ListNode(double value) : val(value), next(NULL) {}
        ListNode(double value, ListNode *next): val(value), next(next) {}    
    };

    int total_elements_in_stream;
    ListNode *head;
    ListNode *last_element;
    ListNode *meadian;

    MedianFinder() 
    {
        total_elements_in_stream = 0;
        head = new ListNode(0);
        last_element = head;
        meadian = head;
    }
    
    void addNum(int num) {
        ListNode *p = new ListNode(num);
        total_elements_in_stream++;
        last_element->next = p;
        last_element = p;

        if(total_elements_in_stream % 2 == 1) {
            if (total_elements_in_stream == 1) {
                meadian = head->next;  // Point to the first real element
            } else {
                meadian = meadian->next;
            }
        }
    }
    
    double findMedian() 
    {
        if(total_elements_in_stream % 2 == 1) {
            return ((double)meadian->val);
        } else {
            return ( double((meadian->val) + (meadian->next->val)) / 2); 
        }
    }
    */


    /*Approach: Think of steam of data. its unsorted. u need to get the sorted stream and in that sorted steam u are
      interested in middle 2 elements at max. since u want to find median. with o(1) only heaps can give u max or min element.
      Now u have stream, plan to devide it. left half and right half. u are interest in maximum value in left half and 
      minimum value in right half. Max value u can get with max heap and min value u can get with min heap in o(1).
      So u need to use 2 heaps. max heap and min heap. All lower values need to go to left half and they need to go to max heap.
      all higher numbers must go to min heap. So while adding if num is less than top element/max element of max heap then its
      added to max heap and if not its to min heap.
      U need to balance the number of elements in both heaps such that left side/max heap at max can have 1 element more than min heap.
       */

    priority_queue<double> left_half;
    priority_queue<double, vector<double>, greater<double>> right_half;

    MedianFinder() 
    {
        
    }

    void addNum(int num) 
    {
        if(left_half.size() == 0 || num < left_half.top()) {
            left_half.push(num);
        } else {
            right_half.push(num);
        }

        /*Balencing. Idea is left half should always be at max one element more than right half. or both can be equal and right half 
          can not be more than left half */

        if(right_half.size() > left_half.size()) {
            left_half.push(right_half.top());
            right_half.pop();
        } else if (left_half.size() > right_half.size() + 1) {
            right_half.push(left_half.top());
            left_half.pop();
        }
    }

    double findMedian() 
    {
        if(((right_half.size() + left_half.size()) % 2) == 1) {
            return ((double) left_half.top());
        } else {
            return (double(((double)right_half.top() + (double)left_half.top())/(double)2) );
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */