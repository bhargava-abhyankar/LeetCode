class Solution {
public:

    /* Method 1: Using priority queue */


    string repeatLimitedString(string s, int repeatLimit) 
    {
	    string ans;
	    vector<int> count(26, 0);
	    priority_queue<pair<char, int>> pq;
	
	    for(int i = 0; i < s.length(); i++) {
		    int index = s[i] - 'a';
		    count[index]++;
	    }

	    for(int i = 0; i < 26; i++) {
            if(count[i])
		        pq.push({i + 'a', count[i]});
	    }

	    while(!pq.empty()) {
		    char cur_char = pq.top().first;
		    int cur_count = pq.top().second;
		    pq.pop();

            int count = min(cur_count, repeatLimit);
        
            for(int i = 0; i < count; i++)
                ans.push_back(cur_char);
        
            cur_count -= count;
        
		    if(cur_count > 0) {
			    if(pq.empty())
				    break;
		
			    char next_char = pq.top().first;
			    int next_count = pq.top().second;
			    pq.pop();
			
                ans.push_back(next_char);
			    next_count--;

			    if(next_count > 0) {
				    pq.push({next_char, next_count});
			    }
			
			    pq.push({cur_char, cur_count});
		    }
	    }
	
	    return ans;
    }


};