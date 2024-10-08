class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0;
        int maxImbalance = 0;

        for(char c : s) {
            if(c == '[') imbalance--;  // an opening bracket reduces the imbalance
            else imbalance++; // a closing bracket increases the imbalance

            // we want to track the maximum imbalance that is happening
            // so that we can fix the imbalances
            maxImbalance = max(maxImbalance, imbalance);
        }

        // minimum swaps needed would be ceil(maxImbalance / 2)
        // since one swap will fix 2 imbalanced brackets
        return (maxImbalance+1) / 2;
    }
};