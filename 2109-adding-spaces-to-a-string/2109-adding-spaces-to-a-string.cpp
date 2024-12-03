class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        
        int j = 0;
        int i = 0;
        while(i < s.size() && j < spaces.size()) {
            if(i == spaces[j]) {
                ans += ' ';
                j++;
            }
            else {
                ans += s[i];
                i++;
            }
        }
        
        while(i < s.size()) {
            ans += s[i];
            i++;
        }
        
        return ans;
    }
};