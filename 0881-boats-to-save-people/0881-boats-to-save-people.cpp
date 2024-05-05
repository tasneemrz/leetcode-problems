class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int countBoats = 0;

        sort(people.begin(), people.end());

        int i = 0, j = people.size()-1;

        while(i <= j) {

            if(i == j) {
                countBoats++;
                i++;
                j--;
                continue;
            }

            int weight = people[i]+people[j];
            
            if(weight <= limit) {
                countBoats++;
                i++;
                j--;
            }
            else if(weight > limit && people[j] <= limit) {
                countBoats++;
                j--;
            }
        }

        return countBoats;
    }
};