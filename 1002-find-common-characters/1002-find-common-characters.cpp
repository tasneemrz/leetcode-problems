class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26, INT_MAX);

        for (int i = 0; i < words.size(); i++) {
            vector<int> curr(26, 0);

            for(char ch : words[i]) {
                curr[ch - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                common[j] = min(curr[j], common[j]);
            }
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            while(common[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                common[i]--;
            }
        }

        return ans;
    }
};