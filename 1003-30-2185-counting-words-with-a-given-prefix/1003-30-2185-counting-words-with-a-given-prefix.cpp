class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(int i = 0; i < words.size(); i++) {
            if(isPrefix(words[i], pref)) {
                ans++;
            }
        }

        return ans;
    }

private:
    bool isPrefix(string word, string pref) {
        int i = 0, j = 0;

        while(i < word.size() && j < pref.size()) {
            if(word[i] != pref[j]) 
                return false;
            i++;
            j++;
        }

        return (j == pref.size()) ? true : false;
    }
};