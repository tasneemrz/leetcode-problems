class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> stringFreq;
        
        for(int i = 0; i < s.length(); i++) {
            string sub = "";
            sub += s[i];
            stringFreq[sub]++;
            
            for(int j = i + 1; j < s.length(); j++) {
                if(s[j] != s[i])
                    break;
                sub += s[j];
                stringFreq[sub]++;
            }
        }
        
        int maxLengthSub = -1;
        
        for(auto& x : stringFreq) {
            if(x.second >= 3) {
                maxLengthSub = max(maxLengthSub, (int)x.first.size());
            }
        }
        
        return maxLengthSub;
    }
};