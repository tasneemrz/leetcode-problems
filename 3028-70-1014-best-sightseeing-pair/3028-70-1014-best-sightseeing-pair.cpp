class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int first = values[0];
        int second;
        int max_pair_sum = 0;
        
        for(int j = 1; j < n; ++j) {
            second = values[j]-j;
            max_pair_sum = max(max_pair_sum, first + second);
            first = max(first, values[j]+j);
        }
        
        return max_pair_sum;
    }
};