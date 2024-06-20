class Solution {
public:

    /*
    This was my first thought. it doesnt work, as it restrict some computation it seems.

    void compute(vector<int>& tokens, int index, int power, int cur_score, int &score_max)
    {
        if(cur_score > score_max) {
           score_max = cur_score; 
        }

	    if(index == tokens.size()) {
		    return;
	    }
	
        for(int i = index; i < tokens.size(); i++) {
	        if(power >= tokens[i]) {
		        compute(tokens, i+1, power-tokens[i], cur_score+1, score_max);
	        }
	
	        if(cur_score > 0) {
		        compute(tokens, i+1, power+tokens[i], cur_score-1, score_max);
	        }
        }
    }
    */

    /*
    The above code was corrected. 
    
    void playTokens(vector<int>& tokens, int tokensSize, int power, int score, int& maxScore, int depth) 
    {
        // Update the maximum score
        if (score > maxScore) {
            maxScore = score;
        }

        // Base case to prevent infinite recursion
        if (depth >= tokensSize) {
            return;
        }

        for (int i = 0; i < tokensSize; i++) {
            
            if (power >= tokens[i]) {
                playTokens(tokens, tokensSize, power - tokens[i], score + 1, maxScore, depth + 1);
            }
            
            if (score >= 1) {
                playTokens(tokens, tokensSize, power + tokens[i], score - 1, maxScore, depth + 1);
            }
        }
    }
    */

    /* This gave time limit exceeded. As we are computing everything. some damm greedy 
        method need to be thought it seems 
        
    void compute(vector<int>& tokens, int power, int cur_score, int &score_max) 
    {
        if (cur_score > score_max) {
            score_max = cur_score;
        }

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == -1) continue; // Skip used tokens

            int tokenValue = tokens[i];
            tokens[i] = -1; // Mark token as used

            // Play token face-up
            if (power >= tokenValue) {
                compute(tokens, power - tokenValue, cur_score + 1, score_max);
            }

            // Play token face-down
            if (cur_score > 0) {
                compute(tokens, power + tokenValue, cur_score - 1, score_max);
            }

            tokens[i] = tokenValue; // Unmark token
        }
    }
    */

    /*
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int ans = 0;
        int depth = 0;

        //compute(tokens, power, 0, ans);
        //playTokens(tokens, tokens.size(), power, 0, ans, depth); 
	    return ans;
    }
    */

    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0;
        int max_score = 0;
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score += 1;
                left += 1;
                max_score = max(max_score, score);
            } else if (score > 0) {
                power += tokens[right];
                score -= 1;
                right -= 1;
            } else {
                break;
            }
        }

        return max_score;
    }
   
    
};