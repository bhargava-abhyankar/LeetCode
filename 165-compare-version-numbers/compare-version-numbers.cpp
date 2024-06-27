class Solution {
public:

    /* Initial nonsense that was writen */

    /*
    int compareVersion(string version1, string version2) 
    {

        int i = 0 , j = 0, v1 = 0, v2 = 0;

        while(i < version1.length()) {
            if(version1[i] == '0') {
                i++;
            } else if (version1[i] == '.') { 
                break;
            } else if(version1[i] == '1') {
                
                while(i < version1.length() && version1[i] != '.')  {
                    int t = (version1[i]-48);
                    v1 = (v1 * 10) + t;
                    i++;
                }
                break;
            }
        }

        while(j < version2.length()) {
            if(version2[j] == '0') {
                i++;
            } else if (version2[j] == '.') { 
                break;
            } else if(version2[j] == '1') {
                
                while(i < version2.length() && version2[j] != '.')  {
                    int t = (version2[j]-48);
                    v2 = (v2 * 10) + t;
                    j++;
                }
                break;
            }
        }

        if(v1 > v2) {
            return 1;
        } else if (v1 < v2) {
            return 1;
        }    
    }

    */

    int compareVersion(string version1, string version2) 
    {
        int i = 0, j = 0;

        while(i < version1.length() || j < version2.length()) {      // this case is or because in case of unequal length also further compare has to happen. eventually greater string will be found

            int v1 = 0, v2 = 0;

            while(i < version1.length() && version1[i] != '.') {
                int digit = (version1[i] - 48);
                v1 = (v1 * 10) + digit;
                i++;
            }

            while(j < version2.length() && version2[j] != '.') {
                int digit = (version2[j] - 48);
                v2 = (v2 * 10) + digit;
                j++;
            }

            if(v1 < v2) {
                return -1;
            } else if (v1 > v2) {
                return 1;
            }
            i++;
            j++;
        }

        return 0;
    }
};