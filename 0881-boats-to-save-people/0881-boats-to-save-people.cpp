class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // sort from light to heavy
        sort(people.begin(), people.end());

        int countBoats = 0;
        int i = 0;
        int j = people.size()-1;

        while(i <= j) {
            // if sum of light and heavy person's weights are less than limit, let them board the boat
            if(people[i]+people[j] <= limit || i == j) {
                i++; // move to the next light person
            }

            // else if sum of weights is greater than limit, let only the heavy person board the boat
            countBoats++;
            j--; // move to the next heavy person
        }

        return countBoats;
    }
};