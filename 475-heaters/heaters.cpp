class Solution {
public:

    /* Initial intution for checking if its covering house or not. complete nonsense .. learn from it. */

        /*
        int count = 0;

        for(int i = 0; i < heaters.size(); i++) {
            for(int j = 0; j < houses.size(); j++) {
                if((houses[j] - radius) <= heaters[i]) {
                    count++;
                }
            }
        }

        if(count > houses.size()) {
            return true;
        } else {
            return false;
        }
        */


    /* Idea is to sort both houses and heater and do binary check and see what is the min no with with all houses will be covered 
       even after identifying this as binary search, trick is find if house gets covered or not. 

       first thing to note is, to check if its falling in range, u need range, that range for given heater is
       heater - radius and heater + radius. if house falls in that then house is covered. if house is not covered then check next heater
       if houses get exhusted before heaters all are covered if heaters get exhausted then the radius need to be increased.
     */

    /* use this all house covered function for range related problem */

    bool is_all_houses_covered(vector<int>& houses, vector<int>& heaters, int radius)
    {
        int cur_house = 0, cur_heater = 0;

        while(cur_house < houses.size()) {

            if(cur_heater >= heaters.size()) {
                return false;
            }

            int low_bound = heaters[cur_heater] - radius;
            int upper_bound = heaters[cur_heater] + radius;

            if((houses[cur_house] <= upper_bound) && (houses[cur_house] >= low_bound)) {
                cur_house++;
            } else {
                cur_heater++;
            }
        }

        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        int n = houses.size(), m = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        /* Mistake:
           int start = 1, end = houses[n-1];    //cann't define start as 1, coz there will be a case where all the heaters will be at all the houses resp.
                                                // cant use end like that as, houses= [1,5] and heater = [10], gives ans as 6 due to binary search exaustion,
                                                // expected ans is 9. 
        */

        int start = 0, end = max(houses[n-1], heaters[m-1]);
  
        while(start <= end) {
            int mid = (start + end)/2;

            if(is_all_houses_covered(houses, heaters, mid)) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return start;
    }
};