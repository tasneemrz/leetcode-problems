class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> hash;

        for(char c : s) {
            hash[c]++;
        }
        
        int len = 0;
        bool odd = false;
        for(auto x : hash) {
            if(x.second % 2 == 0) {
                len += x.second;
            }
            else {
                len += x.second-1;
                odd = true;
            }
        }

        if(odd) return len + 1;
        return len;
    }
};