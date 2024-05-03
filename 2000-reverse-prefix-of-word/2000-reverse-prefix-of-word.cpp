class Solution {
public:
    void reverse(string& word, int indx) {
        int l = 0;
        int r = indx;

        while(l <= r) {
            char temp = word[l];
            word[l] = word[r];
            word[r] = temp;
            l++;
            r--;
        }

        return;
    }

    string reversePrefix(string word, char ch) {
        int indx = 0;

        for(int i = 0; i < word.length(); i++) {
            if(word[i] == ch) {
                indx = i;
                break;
            }
        }

        if(indx == 0) return word;

        reverse(word, indx);

        return word;
    }
};