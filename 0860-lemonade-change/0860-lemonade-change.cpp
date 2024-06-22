class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;
        // no need to keep track of dollar 20 bills as we dont need to return them for change

        for(int bill : bills) {
            if(bill == 5) count5++;

            else if(bill == 10) {
                if(count5 == 0) return false;
                count5--;
                count10++;
            }
            else {
                if(count10 > 0 && count5 > 0) {
                    count10--;
                    count5--;
                }
                else if (count5 >= 3) {
                    count5-=3;
                }
                else return false;
            }
        }

        return true;
    }
};