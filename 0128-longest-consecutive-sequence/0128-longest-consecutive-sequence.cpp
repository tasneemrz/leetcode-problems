class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int longest = 1;
        unordered_set<int> list;

        for(int i = 0; i < nums.size(); i++) {
            list.insert(nums[i]);
        }

        for(auto it : list) {
            // if previous element not present in the set, then current element is the starting element of the sequence
            if(list.find(it-1) == list.end()) {
                int count = 1;
                int x = it;
                // if the next element to current element exists, keep iterating
                while(list.find(x+1) != list.end()) {
                    x++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        
        return longest;
    }
};