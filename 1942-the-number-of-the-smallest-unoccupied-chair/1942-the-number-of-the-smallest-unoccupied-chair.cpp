class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // copy the [arrival, leave] times of target friend
        vector<int> targetTime = times[targetFriend];

        // sort the time vector based on the arrival times
        sort(times.begin(), times.end());

        int n = times.size();

        // initialize n chairs 
        vector<int> chairTime(n);

        // iterate through each friend
        for(auto time : times) {
            int arrival_i = time[0];
            int leave_i = time[1];

            // iterate through each chair 
            for(int i = 0; i < n; i++) {

                // if the the occupied time of the ith chair is <= to arrival time of friend
                // this means that chair has now become empty
                if(chairTime[i] <= arrival_i) {
                    // make the friend sit on this chair
                    // set the time of chair to leave time of friend
                    chairTime[i] = leave_i;

                    // if the time[arrival, leave] equals the time of the target friend
                    // just return the chair number
                    if(time == targetTime) return i;
                    break;
                }
            }
        }

        // if no chair was found for the friend then return 0
        return 0;
    }
};