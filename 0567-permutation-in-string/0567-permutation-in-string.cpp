class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> charFreq(26, 0);
        int n = s1.length();
        int m = s2.length();

        for(char c : s1) {
            charFreq[c - 'a']++;
        }

        vector<int> tempCharFreq(26, 0);
        int start = 0, end = start;
        
        while(end < m) {
            tempCharFreq[s2[end] - 'a']++;

            while((end - start + 1) > n) {
                tempCharFreq[s2[start] - 'a']--;
                start++;
            }

            if(charFreq == tempCharFreq) return true;
            end++;
        }
        
        return false;
    }
};