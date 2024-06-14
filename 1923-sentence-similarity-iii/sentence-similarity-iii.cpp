class Solution {
public:

    /* My first intution, which dint work and could not make it work .
       so be careful.
       Below is code which is failing
       */

    /*
    bool areSentencesSimilar(string sentence1, string sentence2) 
    {
        int count = 0;
        unordered_set<string> hash_table;
        int i = 0, j = 0;
        string temp;

        while(i < sentence1.length()) {
            if(i == (sentence1.length()-1)) {
                temp.push_back(sentence1[i]);  
                hash_table.insert(temp);
                temp.clear();              
                i++;
                j = i;
            } else if (sentence1[i] == ' ') {
                hash_table.insert(temp);
                temp.clear();              
                i++;
                j = i;
            } else {
                temp.push_back(sentence1[i]);
                i++;
            }
        }

        i = 0, j = 0;

        while(i < sentence2.length()) {
            if (i == (sentence2.length()-1)) {
                temp.push_back(sentence2[i]);
                if(hash_table.find(temp) == hash_table.end()) {
                    count++;
                    if(count > 1) 
                        return false;
                }
                temp.clear();
                i++;
                j = i;
            } else if(sentence2[i] == ' ') {
                if(hash_table.find(temp) == hash_table.end()) {
                    count++;
                    if(count > 1) 
                        return false;
                }
                temp.clear();              
                i++;
                j = i;
            } else {
                temp.push_back(sentence2[i]);
                i++;
            }
        }
        return true;
    }
    */

    /*Approach is to split the both sentences on space and store them in seperate vector<string> 
      simultaneously checking if they are euqal either at front or at back. if not sentence can not
      be formed
     */

    bool areSentencesSimilar(string s1, string s2) {
        
        int i = 0;
        string temp;
        vector<string> arr1;
        vector<string> arr2;

        if (s1.size() < s2.size()) {
            string temp1 = s1;
            s1 = s2;
            s2 = temp1;
        }

        while(i < s1.length()) {
            if(i == s1.length()-1) {
                temp.push_back(s1[i]);
                arr1.push_back(temp);
                temp.clear();
                i++;
            } else if(s1[i] == ' ') {
                arr1.push_back(temp);
                temp.clear();
                i++;
            } else {
                temp.push_back(s1[i]);
                i++;
            }
        }

        i = 0;

        while(i < s2.length()) {
            if(i == s2.length()-1) {
                temp.push_back(s2[i]);
                arr2.push_back(temp);
                i++;
                temp.clear();
            }
            else if(s2[i] == ' ') {
                arr2.push_back(temp);
                i++;
                temp.clear();
            } else {
                temp.push_back(s2[i]);
                i++;
            }
        }

        int low1 = 0, low2 = 0, high1 = arr1.size()-1, high2 = arr2.size()-1;

        /* Iterate over 2nd string, i.e small string and check against 1st. 
           It has to match either at first or last , if not, s2 can not be formaed
           from s1 by inserting one sentence */

        while(low2 <= high2) {
            if(arr1[low1] == arr2[low2]) {
                low1++;
                low2++;
            } else if( arr1[high1] == arr2[high2]) {
                high1--;
                high2--;
            } else {
                return false;
            }
        }

        return true;
    }
};