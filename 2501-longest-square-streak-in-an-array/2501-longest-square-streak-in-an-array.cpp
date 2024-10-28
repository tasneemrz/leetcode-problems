class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        long long longestSqStreak = -1;

        unordered_set<long long> list(nums.begin(), nums.end());

        for(long long num : nums) {
            long long currSeqLength = 1;
            long long nextSq = num * num;

            while (list.find(nextSq) != list.end()) {
                currSeqLength++;
                nextSq = nextSq * nextSq;
            }

            longestSqStreak = max(longestSqStreak, currSeqLength);
        }

        if(longestSqStreak < 2) return -1;
        else return longestSqStreak;
    } 
};