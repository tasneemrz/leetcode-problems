class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> symbolMap {
            {'I', 1}, {'V',5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
                                   
        int num = symbolMap[s[n-1]];
        for(int i = n-2; i >= 0; i--) {
            if(symbolMap[s[i]] < symbolMap[s[i+1]]) {
                num -= symbolMap[s[i]];
            } else {
                num += symbolMap[s[i]];
            }
        }

        return num;
    }
};