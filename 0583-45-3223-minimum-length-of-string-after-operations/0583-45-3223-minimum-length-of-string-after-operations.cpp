class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> hashMap;
        for(char c : s) {
            hashMap[c]++;
        }

        int ans = 0;
        for(auto x : hashMap) {
            if(x.second % 2 == 0) {
                ans += 2;
            }
            else {
                ans += 1;
            }
        }

        return ans;
    }
};