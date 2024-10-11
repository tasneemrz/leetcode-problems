class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> events;

        // fill in events vector with the arrival and departure times of all friends
        for(int i = 0; i < n; i++) {
            events.push_back({times[i][0], i}); // friends arrival time
            events.push_back({times[i][1], ~i}); // friends departure time
        }
        
        // sort the events based on the times
        sort(events.begin(), events.end());

        // initialize a min-heap for the available chairs
        priority_queue<
            int, 
            vector<int>, 
            greater<int>
        > availableChairs;

        // initialze a min-heap that will track when each chair gets vacated
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>
        > occupiedChairs;

        // iterate through each chair
        // initialy all chairs are available, so add all to the available chairs queue
        for(int i = 0; i < n; i++) {
            availableChairs.push(i);
        }

        // iterate through each event
        for(auto& event : events) {
            int time = event.first; // could be an arrival time or leave time
            int friendIndex = event.second;

            // iterate through oocupiedChairs queue to check if any chair has been realeased
            // occupiedChair{leaveTime, chairNo}
            // the top chair is the chair with the lowest index / chair number
            while(!occupiedChairs.empty() && occupiedChairs.top().first <= time) {
                // push chair number into available chairs queue
                availableChairs.push(occupiedChairs.top().second); 

                // remove the chair from the occupied queue
                occupiedChairs.pop();
            }

            if(friendIndex >= 0) {
                int chair = availableChairs.top();
                availableChairs.pop();

                if(friendIndex == targetFriend) return chair;

                occupiedChairs.push({times[friendIndex][1], chair});
            }
        }

        return -1;
    }
};