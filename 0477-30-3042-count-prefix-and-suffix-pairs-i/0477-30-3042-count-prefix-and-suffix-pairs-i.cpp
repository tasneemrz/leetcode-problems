class Solution {
public:
    bool isPrefix(string s1, string s2) {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if(s1[i] != s2[j]) {
                return false;
            }
            i++;
            j++;
        }

        return (i == s1.size()) ? true : false;
    }

    bool isSuffix(string s1, string s2) {
        int i = s1.size()-1, j = s2.size()-1;
        while(i >= 0 && j >= 0) {
            if(s1[i] != s2[j]) {
                return false;
            }
            i--;
            j--;
        }

        return (i == -1) ? true : false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if(isPrefix(words[i], words[j]) && isSuffix(words[i], words[j])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};