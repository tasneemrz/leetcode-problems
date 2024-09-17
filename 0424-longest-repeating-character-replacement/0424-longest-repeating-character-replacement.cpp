class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;

        for(int i = 0; i < s.length(); i++) {
            int charsChanged = 0;
            int maxFreq = 0;
            int hash[26] = {0};

            for(int j = i; j < s.length(); j++) {
                hash[s[j]-'A']++;
                maxFreq = max(maxFreq, hash[s[j]-'A']);
                charsChanged = (j-i+1) - maxFreq;
                
                if(charsChanged <= k) {
                    maxLength = max(maxLength, j-i+1);
                } else {
                    break;
                }
            }
        }

        return maxLength;
    }
};