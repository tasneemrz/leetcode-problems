class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        for(int i = 0; i < words.size(); i++) {
            string currWord = words[i];

            for(int j = 0; j < words.size(); j++) {
                if(j != i && words[j].find(currWord) != string::npos) {
                    ans.push_back(currWord);
                    break;
                }
            }
        }

        return ans;
    }
};