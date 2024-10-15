class Solution {
public:
    long long minimumSteps(string s) {
        long long totalSwaps = 0;
        long long blackBallCount = 0;
        
        // start iterating from left
        for(char ball : s) {
            // count the black balls encountered from left side
            if(ball == '1') blackBallCount++;

            // when a white ball encountered; add the number of black balls to total swaps 
            // because white ball will need to swap with each of these black balls on the left to reach its position
            else totalSwaps += blackBallCount;
        }
        
        return totalSwaps;
    }
};